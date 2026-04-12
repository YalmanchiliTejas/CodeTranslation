#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<set>
#include<map>
#include<random>
#include<functional>
#include<utility>

typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define pb push_back
#define P pair<int, int>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define VI vector<int>
#define VII vector<VI>

using namespace std;


int N;
ll a[3005], dp[3005][3005];
int main() {
	cin >> N;
	rep(i, N) cin >> a[i], dp[i][i] = 0;
	for (int len = 1; len <= N; len++) {
		for (int i = 0; i + len <= N; i++) {
			int j = i + len;
			if ((N - len) % 2 == 0) {
				dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1]);
			}
			else {
				dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1]);
			}
		}
	}
	cout << dp[0][N] << endl;

	return 0;
}

