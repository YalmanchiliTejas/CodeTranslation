#include <iostream>

using namespace std;

#define HH 100002
#define MOD 1000000007

int n, m;
int two[HH];
bool del[HH];
int ans;

int mod(int x) {
	while (x < 0)
		x += MOD;
	return x % MOD;
}

int parent[HH];
int find(int x) {
	return x == parent[x] ? x : parent[x] = find(parent[x]);
}
void merge(int x, int y) {
	if (find(x) != find(y))
		parent[parent[x]] = parent[y];
}

void sol() {
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	int iso = n;

	int hit = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		if ((!del[a] || !del[b]) || (del[a] && del[b] && find(a) != find(b))) {
			iso--;
			merge(a, b);
		}

		del[a] = del[b] = true;
	}

	ans = two[iso] + (iso == n ? 0 : 1);
	ans = mod(ans);
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		del[i] = false;
	}
}

int main() {
	two[0] = 1;
	for (int i = 1; i < HH; i++)
		two[i] = (two[i - 1] * 2) % MOD;
	
	while (cin >> n >> m && (n || m))
		sol();
}