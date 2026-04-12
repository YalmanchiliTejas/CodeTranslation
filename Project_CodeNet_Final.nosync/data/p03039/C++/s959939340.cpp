#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(int i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[4]={0,1,0,-1},mdy[4]={-1,0,1,0};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll n,m,k;

ll mod_pow(ll x,ll n,ll mod){
	ll res=1;
	while(n>0){
		if(n&1)res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll i_l(ll x){
	return mod_pow(x,MOD-2,MOD);
}
int main(){
	cin>>n>>m>>k;
	ll a_r_c=1;
	for(ll i=n*m-k+1;i<=n*m-2;i++){
		a_r_c*=i;
		a_r_c%=MOD;
	}
	for(ll i=1;i<=k-2;i++){
		a_r_c*=i_l(i);
		a_r_c%=MOD;
	}
	ll tans=0;
	for(int d=1;d<m;d++){
		tans+=(((a_r_c*(m-d))%MOD*((n*n)%MOD))%MOD)*d%MOD;
	}
	ll sans=0;
	for(int d=1;d<n;d++){
		tans+=(((a_r_c*(n-d))%MOD*((m*m)%MOD))%MOD)*d%MOD;
	}
	cout<<(tans+sans)%MOD<<endl;
	return 0;
}