#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
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
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n,m;

int main(){
	cin>>n>>m;
	vl dp(m+1);
	ll res=0;
	for(int j=0;j<n;j++){
		int x;
		cin>>x;
		if(x>m) continue;
		vl DP(m+1);
		(DP[x]+=j+1)%=mod;
		for(int j=0;j<=m-x;j++) (DP[j+x]+=dp[j])%=mod;
		(res+=DP[m]*(n-j))%=mod;
		for(int j=0;j<=m;j++) (dp[j]+=DP[j])%=mod;
	}
	cout<<res<<endl;
}