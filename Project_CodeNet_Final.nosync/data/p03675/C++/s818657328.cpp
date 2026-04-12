#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
int a[210000],b[210000];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,q=1,flag=1,k=0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
        }
        if(n%2==0)
        {
            for(i=1; i<=n/2; i++)
            {
                b[i]=a[n-k];
                k+=2;
            }
            for(i=n; i>n/2; i--)
            {
                b[i]=a[n-q];
                q+=2;
            }
        }
        else
        {
            for(i=1;i<=(n+1)/2;i++)
            {
                b[i]=a[n-k];
                k+=2;
            }
            for(i=n;i>(n+1)/2;i--)
            {
                b[i]=a[n-q];
                q+=2;
            }
        }
        for(i=1; i<=n; i++)
        {
            if(i==1)
                printf("%d",b[i]);
            else
                printf(" %d",b[i]);
        }

        printf("\n");
    }
    return 0;
}
/*
4 2 1 3
*/
