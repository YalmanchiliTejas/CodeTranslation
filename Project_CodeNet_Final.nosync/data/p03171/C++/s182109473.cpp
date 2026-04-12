#include <bits/stdc++.h>

using namespace std;

#define DIM 3009
#define MODULO 1000000007
#define INF 1e11+9
#define amen exit(0)
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define pairll pair<long long,long long>
#define fi first
#define se second
#define ld long double

long long i,j,k,l,n,m;

long long dp[DIM][DIM][2],a[DIM],pr[DIM];

long long rec(long long l,long long r,long long type){
    if(l==r){
        if(type==1)return a[l];
        else return -a[l];
    }

    if(dp[l][r][type]!=-1)return dp[l][r][type];

    long long sum=pr[r]-pr[l-1];

    if(type==1){
        dp[l][r][type]=max(rec(l+1,r,2)+a[l],rec(l,r-1,2)+a[r]);
    }
    else{
        dp[l][r][type]=min(rec(l+1,r,1)-a[l],rec(l,r-1,1)-a[r]);
    }

    return dp[l][r][type];
}

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i],pr[i]=pr[i-1]+a[i];

    memset(dp,-1,sizeof(dp));

    cout<<rec(1,n,1)<<endl;

    return 0;
}
