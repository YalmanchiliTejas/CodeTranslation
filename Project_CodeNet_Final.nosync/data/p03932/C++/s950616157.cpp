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

int h,w;
vvi a,b;

int main(){
	cin>>h>>w;
	a=b=vvi(h,vi(w));
	for(int i=0;i<h;i++) for(int j=0;j<w;j++) cin>>a[i][j];
	if(w==1){
		int res=0;
		for(int i=0;i<h;i++) res+=a[i][0];
		cout<<res<<endl;
		return 0;
	}
	for(int i=0;i<h;i++){
		int t=0;
		for(int j=0;j<w;j++){
			t+=a[i][j];
			if(j&&i+1<h) t-=a[i+1][j-1];
			b[i][j]=t;
		}
	}
	vvi dp(w,vi(w,-inf));
	for(int i=1;i<w;i++) dp[0][i]=b[0][i];
	for(int i=1;i<h;i++){
		vvi DP(w,vi(w));
		for(int j=0;j<w;j++) for(int k=0;k<w;k++){
			if(j) dp[j][k]=max(dp[j-1][k],dp[j][k]);
		}
		for(int j=0;j<w;j++){
			int mx=-inf;
			for(int k=j+1;k<w;k++){
				mx=max(mx,dp[j][k]);
				DP[j][k]=mx+b[i][j]+b[i][k];
			}
		}
		dp=DP;
	}
	int res=0;
	for(int i=0;i<w;i++) for(int j=0;j<w;j++) res=max(res,dp[i][j]);
	cout<<res<<endl;
}