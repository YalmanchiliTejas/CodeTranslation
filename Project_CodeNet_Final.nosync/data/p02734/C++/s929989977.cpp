//Utkarsh.25dec
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 998244353
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
ll dp[3005][3005];
void solve()
{
    ll n,s;
    cin>>n>>s;
    vl v;
    v.pb(0);
    rep(i,n)
    {
        ll c;
        cin>>c;
        v.pb(c);
    }
    rep(i,3005)
        rep(j,3005)
            dp[i][j]=0;
    ll ans=0;    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=s;j++)
        {
            if(j<v[i])
                continue;
            dp[i][j]+=(dp[i-1][j-v[i]]);
            if(j==v[i])
                dp[i][j]+=i;
            dp[i][j]%=mod;
        }
        ll temp=(n-i+1)*(dp[i][s]);
        temp%=mod;
        ans+=temp;
        ans%=mod;
        for(int j=1;j<=s;j++)
        {
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=mod;
        }
    }
    cout<<ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}