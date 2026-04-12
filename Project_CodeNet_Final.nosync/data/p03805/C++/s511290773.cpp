#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<math.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

//const int INF = 1e6;
const int MOD = 1e9 + 7;

const int nmax = 8;
int dp[1<<nmax][nmax];

int main(){
	int N, M;
	int i, j, k;
	cin >> N >> M;
	vector<pair<int, int>> E;
	for (i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		E.push_back(pair<int, int>(a, b));
	}

	for (i = 0; i < 1<<nmax; i++){
		for (j = 0; j < nmax; j++){
			dp[i][j] = 0;
		}
	}
	dp[1][0] = 1;
	for (i = 3; i < 1<<N; i++){
		if (i % 2 == 0) continue;
		for (j = 0; j < N; j++){
			int c = 0;
			for (k = 0; k < N; k++){
				if ((i >> k) % 2 == 0) continue;
				pair<int, int> g(j+1, k+1);
				pair<int, int> h(k+1, j+1);
				if (count(E.begin(), E.end(), g) == 0 && count(E.begin(), E.end(), h) == 0) continue;
				c += dp[i - (1 << j)][k];
			}
			dp[i][j] = c;
		}
	}
	int ans = 0;
	for (j = 1; j < N; j++){
		ans += dp[(1 << N) - 1][j];
	}
	cout << ans << endl;
}
