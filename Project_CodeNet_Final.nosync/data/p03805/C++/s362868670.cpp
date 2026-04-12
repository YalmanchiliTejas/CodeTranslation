#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "map"

using namespace std;
const long long int MOD = 1000000007;

int N,M;
int dp[1000][10];
list <int>edge[10];
int s, e;
queue<int>Q;
int ans;

int Check(int a, int b);

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		edge[s].push_back(e);
		edge[e].push_back(s);
	}
	for (int i = 0; i < 1000; i++) {
		for (int j = 2; j < 10; j++) {
			dp[i][j] = -1;
		}
	}
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		ans += Check((int)pow(2, N) - 1, i);
	}
	cout << ans << endl;
	return 0;
}

int Check(int a, int b) {
	//cout << a << " " << b << endl;
	if (b == 1)return dp[a][b];
	if (dp[a][b] > -1)return dp[a][b];
	dp[a][b] = 0;
	for (auto i = edge[b].begin(); i != edge[b].end(); ++i) {
		//cout << a%(int)pow(2, *i) << " " << (int)pow(2, (*i) - 1) << endl;
		if (a % (int)pow(2, *i) >= (int)pow(2, (*i) - 1)) {
			dp[a][b] += Check(a - (int)pow(2, b - 1), *i);
		}
	}
	return dp[a][b];
}