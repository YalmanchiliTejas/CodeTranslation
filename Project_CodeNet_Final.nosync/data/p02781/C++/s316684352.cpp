#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define inf (int)(3e18)
#define P pair<int,int>
#define mod (int)(1e9+7)

template<class T>inline void chmin(T &a,T b){a=min(a,b);}
template<class T>inline void chmax(T &a,T b){a=max(a,b);}

string N;
int K;
int dp[105][5][2];
signed main(){
	cin>>N>>K;
	dp[0][0][0]=1;
	rep(i,N.size())rep(j,K+1)rep(k,10){
		if(k<N[i]-'0'){
			if(!k){
				dp[i+1][j][1]+=dp[i][j][1];
				dp[i+1][j][1]+=dp[i][j][0];
			}else {
				dp[i+1][j+1][1]+=dp[i][j][1];
				dp[i+1][j+1][1]+=dp[i][j][0];
			}
		}else if(k==N[i]-'0'){
			if(!k){
				dp[i+1][j][1]+=dp[i][j][1];
				dp[i+1][j][0]+=dp[i][j][0];
			}else {
				dp[i+1][j+1][1]+=dp[i][j][1];
				dp[i+1][j+1][0]+=dp[i][j][0];
			}
		}else {
			dp[i+1][j+1][1]+=dp[i][j][1];
		}
	}
	cout<<dp[N.size()][K][0]+dp[N.size()][K][1]<<endl;
}
