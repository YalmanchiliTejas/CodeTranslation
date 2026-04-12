#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;
const LL mod=1e9+7;

LL dp[10010][110][2];

int main(){
	string K;
	cin >> K;
	int N=K.size();
	LL D;
	cin >> D;
	dp[0][0][0]=1;
	rep(i,N){
		int n=K[i]-'0';
		rep(j,D){
			(dp[i+1][(j+n)%D][0]+=dp[i][j][0])%=mod;
			rep(k,10) (dp[i+1][(j+k)%D][1]+=dp[i][j][1])%=mod;
			rep(k,n) (dp[i+1][(j+k)%D][1]+=dp[i][j][0])%=mod;
		}
	}
	LL ans=dp[N][0][0]+dp[N][0][1]-1;
	if(ans<0) ans+=mod;
	cout << ans << endl;

	return 0;
}