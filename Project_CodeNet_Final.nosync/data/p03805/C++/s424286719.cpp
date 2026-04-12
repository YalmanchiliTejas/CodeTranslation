#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#define lp(n) for (int i = 0; i < n; i++)
#define lop(n,i) for (int i = 0; i < n; i++)
#define INT_MAX 2147483647
#define LLINT_MAX 9223372036854775807
#define mod 1000000007
#define ll long long int
using namespace std;


int n, m;
int a, b;
bool g[8][8];
int dp[1 << 7][8];
int main(){
	cin >> n >> m;
	lp(8)
		lop(8, j) {
		g[i][j] = false;
		}
	lp(m) {
		cin >> a >> b;
		g[a - 1][b - 1] = true;
		g[b - 1][a - 1] = true;
	}

	lp(n)dp[0][i] = 0;
	dp[0][0] = 1;
	for(int i=1;i<(1<<(n-1));i++){
		m = i;
		dp[i][0] = 0;
		for (int j = 1; j < 8; j++) {
			dp[i][j] = 0;
			if (m % 2 == 1) {
				lop(n, k) {
					if (g[j][k]) {
						dp[i][j] += dp[i -(1 << (j - 1))][k];
					}
				}
			}
			m = m >> 1;
		}
	}
//	lp(4) {
//		lop(3, j) {
//			cout << i << ' ' << j << ' ' << dp[i][j] << endl;
//		}
//	}
	int ans = 0;
//	cout << (1 << (n - 1)) - 1 << endl;
	lp(n) {
//		cout<< dp[(1 << (n - 1)) - 1][i]<<endl;
		ans += dp[(1 << (n - 1))-1][i];
	}
	cout << ans << endl;
	return 0;
}