#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<cassert>
#include<stack>
#include<fstream>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define chmin(a,b) a=min(a,b)
#define chmax(a,b) a=max(a,b)

int main(){
	string s;
	int K;
	cin>>s>>K;
	ll dp[110][5][2];//dp[i][k][f]:=i文字目までで、非ゼロがk個あって、Sと等しいかがf
	rep(i,s.size())rep(k,K+1)rep(f,2)dp[i][k][f]=0;
	dp[0][0][0]=1;
	dp[0][1][0]=max(0,s[0]-'0'-1);
	dp[0][1][1]=1;
	for(int i=0;i<s.size()-1;i++)rep(k,K+1){
		dp[i+1][k+1][0]+=dp[i][k][0]*9;
		dp[i+1][k+1][0]+=dp[i][k][1]*max(0,s[i+1]-'0'-1);
		dp[i+1][k][0]+=dp[i][k][0];
		dp[i+1][k][0]+=dp[i][k][1]*(s[i+1]!='0');
		dp[i+1][k+1][1]+=dp[i][k][1]*(s[i+1]!='0');
		dp[i+1][k][1]+=dp[i][k][1]*(s[i+1]=='0');
	}
	ll ans=0;
	rep(f,2)ans+=dp[s.size()-1][K][f];
	cout<<ans<<endl;
}
