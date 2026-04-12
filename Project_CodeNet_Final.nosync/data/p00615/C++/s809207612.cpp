#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	while(true) {
		int n, m;
		scanf(" %d %d", &n, &m);
		if(n == 0 && m == 0) break;
		vector<int> v(n + m + 1);
		v[0] = 0;
		rep(i, n + m) {
			scanf(" %d", &v[i + 1]);
		}
		sort(v.begin(), v.end());
		int ans = 0;
		for(int i = 1; i <= n + m; i++) {
			ans = max(v[i] - v[i - 1], ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}