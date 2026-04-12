#include "bits//stdc++.h"
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

#define ALL(v) v.begin(), v.end()
vector<int> T[100000];
bool used[100000];
bool check(int v, int p) {
	for (int to : T[v]) {
		if (to == p) continue;
		if (!check(to, v)) return 0;
		if (used[to]) continue;
		if (used[v]) return 0;
		used[v] = used[to] = 1;
	}
	return 1;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	if (check(0, -1) && used[0]) cout << "Second" << endl;
	else cout << "First" << endl;
}
