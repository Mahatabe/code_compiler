#include <bits/stdc++.h>
using namespace std;

int len;
int i = 0;
bool flag;
char ex[50];
void factor();

bool num()
{
    if(isdigit(ex[i]))
    {
        i++;
        return true;
    }
    return false;
}

bool id()
{
    if(ex[i]>='a' && ex[i]<='e')
    {
        i++;
        return true;
    }
    return false;
}

void term()
{
    factor();
    if(i < len)
    {
        if(flag)
        {
            if(ex[i] == '+'||ex[i] == '-'||ex[i] == '*'||ex[i] == '/')
            {
                flag = true;
                i++;
                term();
            }
            else
            {
                flag = false;
                return;
            }
        }
    }
    else
    	return;
}

void factor()
{
    flag = false;
    if(i < len)
    {
        if(num() || id())
        {
            flag = true;
            return;
        }
        else if(ex[i] == '(')
        {
            i++;
            term();
            if(ex[i] == ')')
            {
                i++;
                flag = true;
                return;
            }
            else
                flag = false;
        }

        else
        {
            i++;
            flag = false;
            return ;
        }
    }
    else
    	return;
}

void exp()
{
    if(strlen(ex)>1)
    {
        term();
        if(flag)
            cout << "Valid expression" << endl;

        else
            cout << "Invalid expression" << endl;
    }

    else if(isdigit(ex[i]) || id())
        cout << "Valid expression" << endl;

    else
        cout << "Invalid expression" << endl;
}

int main()
{

    while(true)
    {
        gets(ex);
        i=0;
        len=strlen(ex);
        exp();
    }
    return 0;
}

