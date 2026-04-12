#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
    char ch=getchar();
    int x=0,f=1;
    while(ch<'0' || ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int main()
{
    char a[4];
    cin>>a;
    if(a[0]==a[1]&&a[0]==a[2])
        printf("No\n");
    else
        printf("Yes\n");
    return 0;
}
