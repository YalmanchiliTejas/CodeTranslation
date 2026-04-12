#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

ll dp[103][2][4];

int main(){
	string n;
	cin >> n;
	int k;
	cin >> k;
	
	int l = n.size();
	
	dp[0][0][0] = 1;
	
	for (int i = 0; i < l; ++i) {
		int D = n[i] - '0';
		for (int smaller = 0; smaller < 2 ; ++smaller) {
			for (int j = 0; j <= k ; ++j) {
				for (int x = 0; x <= (smaller ? 9 : D) ; ++x) {
					int nj = j;
					if(x != 0) nj++;
					if(nj > k) continue;
					dp[i+1][smaller || (x < D)][nj] += dp[i][smaller][j];
				}
			}
		}
	}
	
	cout << dp[l][1][k] + dp[l][0][k] << endl;
	
	return 0;
}
