#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define req(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define qer(i,a,n) for (int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int f[100000];
int main(){
	ll n;int x,m;cin>>n>>x>>m;
  	ll num=x;f[x]=1;int l=0,r=0;
    req(i,2,n){
        num=num*num%m;if(f[num]){l=f[num],r=i;break;}
        f[num]=i;
    }
    ll ans=0;
    rep(i,0,m)if(f[i]){
        if(f[i]<l||l==0)ans+=i;
        else ans+=i*((n-f[i])/(r-l)+1);
    }
    cout<<ans;
    return 0;
}