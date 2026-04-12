#include<stdio.h>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<iostream>
#include<stack>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
#define ll long long
#define MST(vis,x) memset(vis,x,sizeof(vis))
#define maxn 200010
#define maxm 1010
#define INF 0x3f3f3f3f
int main()
{
    ll s1[60];
    ll k,n,x,temp,all;
    while(scanf("%lld",&n)!=EOF)
    {
        all=0;
        for(int a=1;a<=n;a++)
            scanf("%lld",&s1[a]);
        sort(s1+1,s1+1+n);
        while(s1[n]>=n)
        {
            ll temp=s1[n]/n;
            s1[n]%=n;
            for(int a=1;a<=n-1;a++)
                s1[a]+=temp;
            sort(s1+1,s1+1+n);
            all+=temp;
        }
        printf("%lld\n",all);
    }
    return 0;
}
