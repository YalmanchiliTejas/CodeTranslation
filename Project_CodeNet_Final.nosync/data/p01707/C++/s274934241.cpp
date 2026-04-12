#include <iostream>
#include <fstream>
#include <cassert>
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
#include <random>
#include <complex>
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
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<29;
const ll INF=1ll<<58;
const double pi=acos(-1);
const double eps=1e-7;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

ll Pow_mod(ll n,ll p){
	ll r=1;
	for(;p>0;p>>=1){
		if(p&1) r=(r*n)%mod;
		n=(n*n)%mod;
	}
	return r;
}

ll Div(ll n,ll m){
	return n*Pow_mod(m,mod-2)%mod;
}

ll n,d,k;

int main(){
	while(1){
		cin>>n>>d>>k;
		if(!n) break;
		ll res=0,A=d%mod,B=1;
		vl dp(n+1);
		dp[0]=1;
		for(int i=0;i<n;i++){
			vl s(n+2);
			for(int j=1;j<n+2;j++) s[j]=(s[j-1]+dp[j-1])%mod;
			for(int j=0;j<=n;j++){
				int I=j-k+1;
				dp[j]=(s[j]-s[(I>=0?I:0)]+mod)%mod;
			}
			(res+=dp[n]*Div(A,B))%=mod;
			(A*=(d-i-1)%mod)%=mod;
			(B*=i+2)%=mod;
		}
		cout<<res<<endl;
	}
}