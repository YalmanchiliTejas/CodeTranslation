#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define REP(i, a, n) for(int i=a; i<n; i++)
#define INF 100000000
#define ll long long

int dp[1 << 16];
int main()
{
	int N, M, K;
	int D[16], nxt[100];
	int v[100][100];
	cin >> N >> M >> K;
	REP(i, 0, N) nxt[i] = -1;
	REP(i, 0, M) {
		cin >> D[i];
		D[i]--;
		nxt[D[i]] = i;
	}
	REP(i, 0, N) REP(j, 0, K) {
		cin >> v[i][j];
		v[i][j]--;
	}
	REP(i, 0, 1 << M) dp[i] = INF;

	dp[(1 << M) - 1] = 0;
	queue<int> q;
	q.push((1 << M) - 1);
	while (!q.empty()) {
		int qu = q.front();
		q.pop();
		REP(i, 0, K) {
			int next = 0;
			REP(j, 0, M) {
				if((qu >> j) & 1){
					if (nxt[v[D[j]][i]] != -1) {
						next = next | (1 << nxt[v[D[j]][i]]);
					}
				}
			}
			if (dp[next] != INF) continue;
			dp[next] = dp[qu] + 1;
			q.push(next);
		}
	}

	cout << dp[0] << endl;
	return 0;
}