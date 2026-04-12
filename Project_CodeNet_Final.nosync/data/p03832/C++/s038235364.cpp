#include <iostream>
#include <fstream>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<52;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const vi emp;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,-0};
const int DX[8]={-1,-1,-1,0,0,1,1,1},DY[8]={1,0,-1,1,-1,1,0,-1};

ll Pow_mod(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

vl fact(10000);

ll Fact(ll n){
	if(fact[n]) return fact[n];
	if(!n) return fact[n]=1;
	return fact[n]=Fact(n-1)*n%mod;
}

ll Division_mod(ll n,ll m){
	return n*Pow_mod(m,mod-2)%mod;
}

ll Permutation(ll n,ll k){
	return Division_mod(Fact(n),Fact(n-k));
}

int n,a,b,c,d;

int main(){
	cin>>n>>a>>b>>c>>d;
	vvi dp(b-a+2,vi(n+1));
	for(int i=0;i<b-a+2;i++) dp[i][0]++;
	for(int i=1;i<b-a+2;i++) for(int j=1;j<=n;j++){
		for(int k=c;k<=d&&j-(i+a-1)*k>=0;k++) (dp[i][j]+=Division_mod(dp[i-1][j-(i+a-1)*k]*Permutation(n-j+(i+a-1)*k,(i+a-1)*k)%mod,Pow_mod(Fact(i+a-1),k)*Fact(k)%mod))%=mod;
		(dp[i][j]+=dp[i-1][j])%=mod;
	}
	cout<<dp[b-a+1][n]<<endl;
}