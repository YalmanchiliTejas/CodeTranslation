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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=998244353;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

ll Pow(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

const int M=100005;
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

int n;
string s,t;
vvl dp;

ll f(ll i,ll j){
	if(dp[i][j]!=-1) return dp[i][j];
	if(!i&&!j) return dp[i][j]=1;
	ll res=0;
	if(j) res=j*j*f(i,j-1)%mod;
	if(i&&j) (res+=i*j*f(i-1,j))%=mod;
	return dp[i][j]=res;
}

int main(){
	Init();
	cin>>s>>t;
	n=s.size();
	int A=0,B=0;
	for(int i=0;i<n;i++) if(s[i]=='1'){
		if(t[i]=='1') A++;
		else B++;
	}
	if(!B){
		cout<<F[A]*F[A]%mod<<endl;
		return 0;
	}
	dp=vvl(A+1,vl(B+1,-1));
	ll res=0;
	for(int i=0;i<=A;i++){
		(res+=F[i]*F[i]%mod*nCk(A,i)%mod*nCk(A+B,i)%mod*f(A-i,B)%mod)%=mod;
	}
	cout<<res<<endl;
}