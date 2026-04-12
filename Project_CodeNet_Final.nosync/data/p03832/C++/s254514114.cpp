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

#define M 1000000007

ll fact[11111];
ll finv[11111];

//// extended gcd
ll extgcd(ll a,ll b,ll& x,ll& y){
	ll d=a;
	if(b!=0){
		d=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}else{
		x=1;y=0;
	}
	return d;
}

//// mod inverse
ll mod_inverse(ll a,ll m){
	ll x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}

//// mod combination ex.( num of route (0,0)->(x,y)=mod_comb(x+y,x,M)
ll mod_comb(int n,int k,int p){
	if(n<0||k<0||n<k)return 0;
	return ((fact[n]*finv[k])%p)*finv[n-k]%p;
}

//// mod power
ll mod_pow(ll x,ll n,ll mod){
	ll res=1;
	while(n>0){
		if(n&1)res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll dp[1111][1111];
ll a,b,c,d;

int main(){
	cin.sync_with_stdio(false);
	fact[0]=fact[1]=1;
	finv[0]=finv[1]=mod_inverse(1,M);
	repl(i,1,10000){
		fact[i+1]=(fact[i]*(i+1))%M;
		finv[i+1]=mod_inverse(fact[i+1],M);
	}
	ll n;
	cin>>n>>a>>b>>c>>d;
	dp[0][a-1]=1;
	rep(i,n+1)repl(j,a,b+1){
		dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
		for(int k=c;i+j*k<=n&&k<=d;k++){
			dp[i+j*k][j]=(dp[i+j*k][j]+(((((((dp[i][j-1]*fact[n-i])%M)*finv[n-i-k*j])%M)*finv[k])%M)*mod_pow(finv[j],k,M))%M)%M;
		}
	}
	cout<<dp[n][b]<<endl;
	return 0;
}
