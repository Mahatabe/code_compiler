#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char str[100];

bool stat(int sta, int fin);
bool asgn_stat(int sta, int fin);
bool idnt(int sta, int fin);

bool stat(int sta, int fin)
{
    if(asgn_stat(sta, fin))
        return true;
    else if(dscn_stat(sta, fin))
        return true;
    else if(loop_stat(sta, fin))
        return true;
    else
        return false;
}

bool asgn_stat(int sta, int fin)
{
    int j = sta;

    while(j <= fin && str[j] != '=')
        ++j;
    if(j == fin)
        return false;
    else if(str[j] == '=')
        return (idnt(sta, j-1) && expn(j + 1, fin));
    else
        return false;
}

bool idnt(int sta, int fin)
{
    if(isalpha(str[sta]) || str[sta] == '_')
    {
        int j = sta + 1;

        while(j <= fin)
        {
            if(!isalnum(str[j]) && str[j] != '_')
                break;
            ++j;
        }

        if(j == fin + 1)
            return true;
        return false;
    }
    return false;
}

int main(void)
{
    gets(str);
    int len = strlen(str);

    if(stat(0, len - 1))
        printf("Accepted by Grammar.\n");
    else
        printf("Rejected by Grammar.\n");

    return 0;
}
