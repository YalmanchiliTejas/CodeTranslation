#include <iostream>
#include <string>
using namespace std;
int D;
int inf = 1e9+7;
int dp[10010][2][101] = {{{0}}};//何文字目か，小さいか，modD
string K;

int main(){
	cin >> K;
	cin >> D;
	int n = K.size();
	dp[0][0][0] = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<D;k++){
				int m = j ? 9 : K[i] - '0'; //j==1ならなんでもOK
				for(int l=0;l<m+1;l++){
					(dp[i+1][j || l<m][(k+l)%D] += dp[i][j][k])%=inf;
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<2;i++){
		(ans += dp[n][i][0])%=inf;
	}
	cout << (ans-1+inf)%inf << endl;
}
