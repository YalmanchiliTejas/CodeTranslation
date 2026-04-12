#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mm(a,x) memset(a,x,sizeof(a))
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0)
#define ll long long
using namespace std;
const int MAXN=3e3+10;
const int MOD=998244353;
int a[MAXN];
ll dp[MAXN];
int main(void)
{
    sync;
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int res=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=s;j>a[i];--j)
            dp[j]=(dp[j]+dp[j-a[i]])%MOD;
        dp[a[i]]=(dp[a[i]]+i)%MOD;
        res=(res+(n-i+1)*dp[s]%MOD)%MOD;
        dp[s]=0;
    }
    cout<<res<<endl;
    return 0;
}