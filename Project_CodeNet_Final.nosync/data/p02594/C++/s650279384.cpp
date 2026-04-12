#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define fi first
#define se second
#define lc T[p].l
#define rc T[p].r
#define mid (l+r>>1)
#define lson lc,l,mid
#define rson rc,mid+1,r
#define sum T[p].val
#define pii pair<int,int>
const int MX=1e6+7;
const int mod=998244353;
const double pi=3.1415926535897932384;
double isp=1e-13;
using namespace std;
ll qpow(ll a,ll b,ll MOD=mod){for(ll ans=1;;a=a*a%MOD,b>>=1){if(b&1)ans=ans*a%MOD;if(!b)return ans;}}
ll inv(ll a,ll MOD=mod){return qpow(a,MOD-2,MOD);}//要求MOD为质数
ll exgcd(ll a,ll b,ll &x,ll &y){if(b==0){x=1,y=0;return a;}ll ret=exgcd(b,a%b,y,x);y-=a/b*x;return ret;}
ll getInv(int a,int mod){ll x,y;ll d=exgcd(a,mod,x,y);return d==1?(x%mod+mod)%mod:-1;}//求a在mod下的逆元，不存在逆元返回-1，不要求MOD为质数
ll mx[MX],a[10];
void solve()
{
    int n;
    cin>>n;
    if(n>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
int main()
{
  ios::sync_with_stdio(0),cin.tie(0);
  int t;
 // cin>>t;
  t=1;
  while(t--)
  {
      solve();
  }
}
