#include<bits/stdc++.h>
using namespace std;

const int N = 3005;
long long dp[N][N][2];
bool vis[N][N][2];
int arr[N];
int n;

long long  rec(int l,int r,int f)
{
    if(l>r) return 0;
    long long &ret=dp[l][r][f];
    if(vis[l][r][f]) return ret;
    vis[l][r][f]=1;
    if(f==0)
    {
        ret=-1e16;
        ret=max(ret,arr[l]+rec(l+1,r,f^1));
        ret=max(ret,arr[r]+rec(l,r-1,f^1));
    }
    else
    {
        ret=1e16;
        ret=min(ret,-arr[l]+rec(l+1,r,f^1));
        ret=min(ret,-arr[r]+rec(l,r-1,f^1));
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++) scanf("%d",&arr[i]);
    printf("%lld\n",rec(1,n,0));



}
