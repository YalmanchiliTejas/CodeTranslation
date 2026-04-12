#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define mod 1000000007
#define LL long long

int n;
char s[1000005];
int a[1000005];

int judge()
{
    for(int i=1;i<=n;++i)
    {
        if(i==1)
        {
            if(a[1]==0)
            {
                if(s[1]=='o')
                    if(a[2]!=a[n]) return 0;
                if(s[1]=='x')
                    if(a[2]==a[n]) return 0;
            }
            if(a[1]==1)
            {
                if(s[1]=='o')
                    if(a[2]==a[n]) return 0;
                if(s[1]=='x')
                    if(a[2]!=a[n]) return 0;
            }
        }
        if(i==n)
        {
            if(a[n]==0)
            {
                if(s[n]=='o')
                    if(a[1]!=a[n-1]) return 0;
                if(s[n]=='x')
                    if(a[1]==a[n-1]) return 0;
            }
            if(a[n]==1)
            {
                if(s[n]=='o')
                    if(a[1]==a[n-1]) return 0;
                if(s[n]=='x')
                    if(a[1]!=a[n-1]) return 0;
            }
        }
        if(i>1&&i<n)
        {
            if(a[i]==0)
            {
                if(s[i]=='o')
                    if(a[i-1]!=a[i+1]) return 0;
                if(s[i]=='x')
                    if(a[i-1]==a[i+1]) return 0;
            }
            if(a[i]==1)
            {
                if(s[i]=='o')
                    if(a[i-1]==a[i+1]) return 0;
                if(s[i]=='x')
                    if(a[i-1]!=a[i+1]) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s",s+1);
        ///00
        memset(a,-1,sizeof(a));
        a[1]=0,a[2]=0;
        for(int i=2;i<n;++i)
        {
            if(a[i]==0)
            {
                if(s[i]=='o')
                    a[i+1]=a[i-1];
                if(s[i]=='x')
                    a[i+1]=1-a[i-1];
            }
            if(a[i]==1)
            {
                if(s[i]=='o')
                    a[i+1]=1-a[i-1];
                if(s[i]=='x')
                    a[i+1]=a[i-1];
            }
        }//for(int i=1;i<=n;++i) cout<<a[i];cout<<endl;
        if(judge())
        {
            for(int i=1;i<=n;++i)
            {
                if(a[i]==0) printf("S");
                if(a[i]==1) printf("W");
            }
            printf("\n");
            continue;
        }

        ///01
        memset(a,-1,sizeof(a));
        a[1]=0,a[2]=1;
        for(int i=2;i<n;++i)
        {
            if(a[i]==0)
            {
                if(s[i]=='o')
                    a[i+1]=a[i-1];
                if(s[i]=='x')
                    a[i+1]=1-a[i-1];
            }
            if(a[i]==1)
            {
                if(s[i]=='o')
                    a[i+1]=1-a[i-1];
                if(s[i]=='x')
                    a[i+1]=a[i-1];
            }
        }//for(int i=1;i<=n;++i) cout<<a[i];cout<<endl;
        if(judge())
        {
            for(int i=1;i<=n;++i)
            {
                if(a[i]==0) printf("S");
                if(a[i]==1) printf("W");
            }
            printf("\n");
            continue;
        }

        ///11
        memset(a,-1,sizeof(a));
        a[1]=1,a[2]=1;
        for(int i=2;i<n;++i)
        {
            if(a[i]==0)
            {
                if(s[i]=='o')
                    a[i+1]=a[i-1];
                if(s[i]=='x')
                    a[i+1]=1-a[i-1];
            }
            if(a[i]==1)
            {
                if(s[i]=='o')
                    a[i+1]=1-a[i-1];
                if(s[i]=='x')
                    a[i+1]=a[i-1];
            }
        }//for(int i=1;i<=n;++i) cout<<a[i];cout<<endl;
        if(judge())
        {
            for(int i=1;i<=n;++i)
            {
                if(a[i]==0) printf("S");
                if(a[i]==1) printf("W");
            }
            printf("\n");
            continue;
        }

        ///10
        memset(a,-1,sizeof(a));
        a[1]=1,a[2]=0;
        for(int i=2;i<n;++i)
        {
            if(a[i]==0)
            {
                if(s[i]=='o')
                    a[i+1]=a[i-1];
                if(s[i]=='x')
                    a[i+1]=1-a[i-1];
            }
            if(a[i]==1)
            {
                if(s[i]=='o')
                    a[i+1]=1-a[i-1];
                if(s[i]=='x')
                    a[i+1]=a[i-1];
            }
        }//for(int i=1;i<=n;++i) cout<<a[i];cout<<endl;
        if(judge())
        {
            for(int i=1;i<=n;++i)
            {
                if(a[i]==0) printf("S");
                if(a[i]==1) printf("W");
            }
            printf("\n");
            continue;
        }
        printf("-1\n");
    }
}
