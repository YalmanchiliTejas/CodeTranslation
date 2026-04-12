#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
vector<int>a;
vector<int>b;
vector<int>used;
int ans = 0;
int verp = 1;
int n, m;
void bfs(int x) {
	if (verp == n) {
		ans++;
		return;
	}
	for (int i = 0; i < m; ++i) {
		if (a[i] == x && used[b[i]] == 0) {
			used[b[i]] = 1;
			verp++;
			bfs(b[i]);
			used[b[i]] = 0;
			verp--;
		}
		else if (b[i] == x && used[a[i]] == 0) {
			used[a[i]] = 1;
			verp++;
			bfs(a[i]);
			used[a[i]] = 0;
			verp--;
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int tmpa, tmpb;
		cin >> tmpa >> tmpb;
		tmpa--; tmpb--;
		a.push_back(tmpa);
		b.push_back(tmpb);
		used.push_back(0);
	}
	used[0] = 1;
	bfs(0);
	cout << ans << endl;
	return 0;
}