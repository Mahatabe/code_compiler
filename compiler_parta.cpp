#include<bits/stdc++.h>
using namespace std;

bool flag=true;
char s[50];
int len,i=0;

void X()
{
    if(s[i]=='b')
    {
        i++;
        if(s[i]=='b' || s[i]=='c')
        {
            i++;
            X();
        }
        else
        {
            flag=false;
            return;
        }

    }
    else
    {
       return;
    }
}
bool A()
{
    if(s[i]=='a')
    {
        i++;
        X();
        if(s[i]!='d')
        {
           flag=false;
           return flag;
        }
        else
            return flag;
    }
    else
    {
        flag=false;
        return flag;
    }
}
int main()
{
    while(true)
    {
        gets(s);
        len=strlen(s);
        flag=true;
        i=0;
        if(A())
            cout<<"Accepted"<<endl;
        else
            cout<<"not accepted"<<endl;
    }
}

