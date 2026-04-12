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
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int k;
string s;

int main(){
	cin>>s>>k;
	int n=s.size();
	vvl dp(k+1,vl(2));
	for(int i=0;i<n;i++){
		vvl DP(k+1,vl(2));
		int t=s[i]-'0';
		if(i==0){
			DP[1][0]+=t-1;
			DP[1][1]++;
		}
		else DP[1][0]+=9;
		for(int j=0;j<=k;j++){
			for(int l=0;l<10;l++){
				int I=j+(l?1:0);
				if(I<=k) DP[I][0]+=dp[j][0];
				if(I<=k&&l<=t) DP[I][(l<t?0:1)]+=dp[j][1];
			}
		}
		dp=DP;
//		for(int j=0;j<=k;j++) cout<<dp[j][0]<<' '<<dp[j][1]<<endl;
//		cout<<endl;
	}
	cout<<dp[k][0]+dp[k][1]<<endl;
}