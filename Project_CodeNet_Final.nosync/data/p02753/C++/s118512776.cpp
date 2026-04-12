#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
main()
{
    char s[5];
    int a=0,b=0,i;
    cin>>s;
    for(i=0;i<=2;i++)
    {
        if(s[i]=='A')
        {
            a=1;
        }
        else
        {
            b=1;
        }
    }
    if(a==1 && b==1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}

