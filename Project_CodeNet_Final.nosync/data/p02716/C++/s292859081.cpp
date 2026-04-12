#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cout<<' ';cout<<elem;}cout<<endl;}

//解説参考.
int main(){
	int n;
	cin>>n;
	
	vector<llong> a(n);
	REP(i,n) cin>>a[i];
	
	vector<vector<llong> > dp(n,vector<llong>(2));
	dp[0][0]=dp[0][1]=0;
	dp[1][0]=a[0];
	dp[1][1]=a[1];
	for(int i=2;i<n;++i){
		if(i&1){
			dp[i][0]=dp[i-2][0]+a[i-1];
			dp[i][1]=dp[i-1][0]+a[i];
		}else{
			dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
			dp[i][1]=max(dp[i-2][0],dp[i-2][1])+a[i];
		}
	}
	
	/*REP(i,n) cout<<dp[i][0]<<' ';
	cout<<endl;
	REP(i,n) cout<<dp[i][1]<<' ';
	cout<<endl;*/
	
	cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
}