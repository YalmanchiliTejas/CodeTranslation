#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 10;
vector<int> Mat[MAXN], d;
int n, cnt[MAXN];
bool ok = 0;

bool dfs(int v, int p) {
	int cnt = 0;
	for (int i = 0; i < Mat[v].size(); i++)
		if (Mat[v][i] != p)
			cnt += dfs(Mat[v][i], v);
	if (cnt == 0)
		return 1;
	if (cnt == 1)
		return 0;
	ok = 1;
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		Mat[a].push_back(b);
		Mat[b].push_back(a);
	}
	int s = 0;
	for (int i = 1; i <= n; i++)
		if (Mat[i].size() > 1)
			s = i;
	if (s == 0)
		return cout << "Second", 0;
	if (dfs(s, s) || ok)
		cout << "First";
	else
		cout << "Second";
}