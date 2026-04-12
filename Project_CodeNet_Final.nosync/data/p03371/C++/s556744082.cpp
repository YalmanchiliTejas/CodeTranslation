#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define SZ(x) ((int)(x).size())
#define MEM(x,a) memset(x,a,sizeof(x))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
const ll mod=1000000007,N=1e5+5,M=1e5+5,INF=0x3f3f3f3f;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//head

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,x,y;
    ll ans=INF;
    cin>>a>>b>>c>>x>>y;
    rep(i,0,max(x,y)+1){
        ll tmp=i*c*2;
        tmp+=max(0ll,x-i)*a+max(0ll,y-i)*b;
        ans=min(ans,tmp);
    }
    cout<<ans;
    return 0;
}