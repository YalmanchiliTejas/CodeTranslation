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
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

string s;
int m;
vi dp;

int main(){
	cin>>s>>m;
	int n=s.size(),t=0;
	dp=vi(m);
	for(int i=0;i<n;i++){
		vi DP(m);
		for(int j=0;j<10;j++) for(int k=0;k<m;k++) (DP[(j+k)%m]+=dp[k])%=mod;
		for(int j=0;j<s[i]-'0';j++) (DP[(t+j)%m]+=1)%=mod;
		dp=DP;
		t+=s[i]-'0';
	}
	if(t%m==0) dp[0]++;
	cout<<(dp[0]-1+mod)%mod<<endl;
}