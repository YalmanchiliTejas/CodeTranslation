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
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll n;
vl a;

int main(){
	cin>>n;
	a=vl(n);
	for(auto &i:a) cin>>i;
	vector<map<ll,ll>> dp(n+1);
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=(i+1)/2;j>0;j--){
			ll tmp=-INF;
			for(int k=1;k<=5;k++) if(i-k>=0&&dp[i-k].find(j-1)!=dp[i-k].end()){
				if(i>1&&k==1) continue;
				tmp=max(tmp,dp[i-k][j-1]+a[i-1]);
			}
			dp[i][j]=tmp;
			if(cnt==10) break;
			cnt++;
		}
	}
	ll res=-INF;
	for(int i=0;i<=n;i++) if(dp[i].find(n/2)!=dp[i].end()) res=max(res,dp[i][n/2]);
	cout<<res<<endl;
}