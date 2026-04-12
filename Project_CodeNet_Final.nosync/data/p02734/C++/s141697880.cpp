#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define pi pair<int, int>
#define mk make_pair
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N=3e3+10;
const ll mod=998244353;
int a[N],n,s,len;
ll dp[N][N],f[N];

int main()
{
    cin>>n>>s;
    rep(i,1,n)
    {
        cin>>a[i];
    }

    //dp[0][0]=1;
    for(int i=1;i<=n;++i){
        dp[i][a[i]]=i;
        for(int j=0;j<=s;++j){
            if(j+a[i]>s) continue;
            dp[i][j+a[i]]+=f[j];
            dp[i][j+a[i]]%=mod;;
        }
        for(int j=0;j<=s;++j) f[j]+=dp[i][j],f[j]%=mod;
    }
    //printf("dp[]:%d\n",dp[3][4]);

    ll ans=0;
    for(int i=1;i<=n;++i){
        ans+=(1ll*n-i+1)*dp[i][s]%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}
