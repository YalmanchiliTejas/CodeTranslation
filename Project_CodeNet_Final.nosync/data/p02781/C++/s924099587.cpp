#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const int MOD=1000000007;

ll dp[200][2][5];
int main(){
	string s;int K;cin>>s>>K;
	dp[0][0][0]=1;
	rep(i,s.size())rep(j,2)rep(k,K+1){
		int lim=(j?9:s[i]-'0');
		for(int t=0;t<=lim;t++){
			dp[i+1][j||t<lim][k+(t>0)]+=dp[i][j][k];
		}
	}
	ll ans=0;
	rep(i,2){
		ans+=dp[s.size()][i][K];
	}
	cout<<ans<<endl;
}