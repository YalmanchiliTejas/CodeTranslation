// Charan Sriramula

#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;

const ll logx=30;
const ll N=1e4+5;
const ll INF=1e18+5;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;

#define ints(n) scanf("%d",&n)
#define intp(n) printf("%d\n",n)
#define longs(n) scanf("%intd",&n)
#define longp(n) printf("%intd\n",n)

inline ll mul(ll a, ll b){ return (a * 1ll * b) % mod; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += mod; return c; }
inline ll add(ll a, ll b){ ll c = a + b; if(c > mod) c -= mod; return c; }

#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x,y) make_pair(x,y)
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcount(x)
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define ms(dp,val) memset(dp,val,sizeof(dp))
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
template<typename T> T power(T x,T y,ll m){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1ll;x=(x*x)%m;}return ans%m;}

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

ll cur,d;
vector<ll> dig[2];
ll dp[N][105][2];

void len(string n)
{
  for(ll i=0;i<n.length();i++){dig[cur].pb(n[i]-'0');}
  //while(n){dig[cur].pb(n%10);n/=10;}
  //reverse(all(dig[cur]));
}

ll F(ll idx,ll rem,ll f)
{
	ll res=0;
	if(idx==dig[cur].size()){return rem%d==0;}
	if(dp[idx][rem][f]!=-1){return dp[idx][rem][f];}
  if(f)
  {
		for(ll i=0;i<dig[cur][idx];i++){res=add(res,F(idx+1,(rem+i)%d,0));}
		res=add(res,F(idx+1,(rem+dig[cur][idx])%d,1));
  }
  else
  {
    for(ll i=0;i<=9;i++){res=add(res,F(idx+1,(rem+i)%d,0));}
  }
	return dp[idx][rem][f]=res;
}

int main()
{
	string k;
	cin>>k>>d;
	len(k);
	ms(dp,-1);
	ll val=F(0,0,1);
	val=sub(val,1LL);
	cout<<val<<endl;
}
