#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <iomanip>
using namespace std;
#define pb push_back
#define pf push_fron
#define INF 1e9
#define PI acos(-1)
typedef long long ll;

vector<int> edge[10];

int main() {
	
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a].pb(b); edge[b].pb(a);
	}

	int pm[10];
	for (int i = 0; i < n; i++)pm[i] = i;

	bool flag[10];
	do {
		if (pm[0] != 0)continue;
			for (int i = 0; i < n; i++) flag[i] = false;
			flag[0] = true;
			for (int i = 0; i < n-1; i++) {
				for (vector<int>::iterator it = edge[pm[i]].begin(); it != edge[pm[i]].end(); it++) {
					if (*it == pm[i + 1] && !flag[pm[i+1]]) {
						flag[pm[i + 1]] = true;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				if (!flag[i]) break;
				if (i == n - 1) ans++;
			}
		
	} while (next_permutation(pm, pm + n));

	cout << ans << endl;

	return 0;
}