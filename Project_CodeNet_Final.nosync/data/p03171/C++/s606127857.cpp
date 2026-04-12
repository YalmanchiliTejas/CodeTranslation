#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn=3000;
typedef long long ll;

ll dp[maxn][maxn][2];
ll l[maxn];

int main(){
	int n;
	scanf("%d", &n);
	bool p=(n+1)%2;
	for(int i=0; i<n; i++){
		scanf("%lld", &l[i]);
		dp[i][i][p]=l[i];
	}
	for(int j=1; j<n; j++){
		p^=1;
		for(int i=0; i+j<n; i++){
			dp[i][i+j][p^1]=min(dp[i+1][i+j][p^1], dp[i][i+j-1][p^1]);
			dp[i][i+j][p]=max(dp[i+1][i+j][p]+l[i], dp[i][i+j-1][p]+l[i+j]);
		}
	}
	printf("%lld\n", dp[0][n-1][0]-dp[0][n-1][1]);
	return 0;
}