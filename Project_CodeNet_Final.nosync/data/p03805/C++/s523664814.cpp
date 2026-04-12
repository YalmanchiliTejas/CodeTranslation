#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

vector<vector<int>> P;
int N, M, ans = 0;

void bfs(int v, map<int, int> used, int cnt)
{
  cnt++;
  if (cnt == N) ans++;
  if (used[v]) return;
  used[v] = 1;
  for (auto t : P.at(v)) {
    if (used[t]) continue;
    bfs(t, used, cnt);
  }
}

int main()
{
	map<int, int> used;
	cin >> N >> M;
	P.resize(N);
	rep(i, M) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		P.at(x).push_back(y);
		P.at(y).push_back(x);
	}

	bfs(0, used, 0);
	cout << ans << endl;
	return 0;
}