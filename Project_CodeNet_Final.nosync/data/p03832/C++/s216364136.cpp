#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define maxch(x,y) x=max(x,y)
#define minch(x,y) x=min(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt(x) bitset<32>(x).count()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<P, int> PPI;
typedef pair<ll, ll> PL;
typedef pair<P, ll> PPL;

#define INF INT_MAX/3

#define MAX_N 1000

const int mod = 1000000007;
struct mint {
  ll x;
  mint():x(0){}
  mint(ll x):x((x%mod+mod)%mod){}
  mint& fix() { x = (x%mod+mod)%mod; return *this;}
  mint& operator+=(const mint& a){ if((x+=a.x)>=mod) x-=mod; return *this;}
  mint& operator-=(const mint& a){ if((x+=mod-a.x)>=mod) x-=mod; return *this;}
  mint& operator*=(const mint& a){ (x*=a.x)%=mod; return *this;}
  mint operator+(const mint& a)const{ return mint(*this) += a;}
  mint operator-(const mint& a)const{ return mint(*this) -= a;}
  mint operator*(const mint& a)const{ return mint(*this) *= a;}
  mint operator^(const mint& a)const{
  	ll res=1,n=a.x,xx=x;
	while(n>0){
		if(n&1)res=res*xx%mod;
		xx=xx*xx%mod;
		n>>=1;
	}
  	return mint(res);
  }
  mint operator/(const mint& a)const{ return mint(*this)*(a^(mod-2)); }
  bool operator<(const mint& a)const{ return x < a.x;}
  bool operator==(const mint& a)const{ return x == a.x;}
};
istream& operator>>(istream&i,mint&a){i>>a.x;return i;}
ostream& operator<<(ostream&o,const mint&a){o<<a.x;return o;}

mint dp[1111][1111];
mint fact[11111];
mint finv[11111];
ll a,b,c,d;

int main(){
	cin.sync_with_stdio(false);
	fact[0].x=fact[1].x=1;
	finv[0].x=finv[1].x=1;
	repl(i,1,10000){
		fact[i+1]=fact[i]*mint(i+1);
		finv[i+1]=mint(1LL)/fact[i+1];
	}
	ll n;
	cin>>n>>a>>b>>c>>d;
	dp[0][a-1].x=1;
	rep(i,n+1)repl(j,a,b+1){
		dp[i][j]+=dp[i][j-1];
		for(int k=c;i+j*k<=n&&k<=d;k++){
			dp[i+j*k][j]+=dp[i][j-1]*fact[n-i]*finv[n-i-k*j]*finv[k]*(finv[j]^k);
		}
	}
	cout<<dp[n][b].x<<endl;
	return 0;
}
