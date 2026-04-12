#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
ll mod;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll Pow(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

const int M=3005;
ll F[M];

void Init(){
	F[0]=1;
	for(int i=1;i<M;i++) F[i]=F[i-1]*i%mod;
}

ll Div(ll n,ll m){
	return n*Pow(m,mod-2)%mod;
}

ll nCk(ll n,ll k){
	return Div(F[n],F[n-k]*F[k]%mod);
}

ll n,a[M],dp[M][M];

int main(){
	cin>>n>>mod;
	Init();
	a[0]=2;
	for(int i=1;i<M;i++) a[i]=(a[i-1]*a[i-1])%mod;
	for(int i=0;i<M;i++) dp[i][0]=1;
	for(int i=1;i<M;i++) for(int j=1;j<=i;j++) dp[i][j]=(dp[i-1][j-1]+(1+j)*dp[i-1][j])%mod;
	ll res=a[n];
	for(int i=1;i<=n;i++){
		ll tmp=0;
		for(int j=0;j<=i;j++) (tmp+=dp[i][j]*Pow(2,j*(n-i)))%=mod;
		(tmp*=nCk(n,i))%=mod;
		(tmp*=a[n-i])%=mod;
		if(i%2==1) (tmp*=mod-1)%=mod;
		(res+=tmp)%=mod;
	}
	cout<<res<<endl;
}