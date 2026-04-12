#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[100000+1000][2][200];
const int pri=1000000007;

signed main(){
	string S; int D; cin>>S>>D;
	dp[0][0][0]=1;
	int N=S.size();
	for(int i=0;i<N;i++){
		for(int smaller=0;smaller<2;smaller++){
			for(int j=0;j<=D;j++){
				for(int x=0;x<=(smaller ? 9 : S[i]-'0');x++){
					dp[i+1][smaller or x<(S[i]-'0')][(j+x)%D]+=dp[i][smaller][j];
					dp[i+1][smaller or x<(S[i]-'0')][(j+x)%D]%=pri;
				}
			}
		}
	}
	cout<< (dp[N][0][0]+dp[N][1][0]-1 + pri)%pri<<endl;
}
