#include<bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
#define vec vector<ll>
#define mat vector<vector<ll> >
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef complex<double> comp;
const ll INF=1e9+7;
const ll inf=INF*INF;
const ll MOD=998244353;
const ll mod=MOD;
const int MAX=200010;

signed main(){
    ll n;cin>>n;
    ll x,m;cin>>x>>m;
    ll ans=0;
    vector<ll>used(m,-1);
    vector<ll>sum(m+1);
    vector<ll>c(0);
    ll now=0;
    while(used[x]<0){
        used[x]=now;
        if(now)sum[now]=sum[now-1]+x;
        else sum[now]=x;
        x=x*x%m;
        now++;
    }
    sum[now]+=sum[now-1]+x;
    if(n<=now){
        cout<<sum[n-1]<<endl;
    }else{
        ans+=sum[used[x]];
        ll s=now-used[x];
        ll v=sum[now]-sum[used[x]];
        n-=used[x]+1;
        ans+=(n/s)*v;
        ans+=sum[used[x]+n%s]-sum[used[x]];
        cout<<ans<<endl;
    }
}