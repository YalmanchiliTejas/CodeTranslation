#include <cstdio>
#include <vector>

using namespace std;
typedef long long ll;

ll opt[3010][3010];

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n); for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; --i) {
		opt[i][i] = a[i];
		for (int j = i + 1; j < n; ++j) {
			opt[i][j] = max(a[i] - opt[i+1][j], a[j] - opt[i][j-1]);
		}
	}
	printf("%lld\n", opt[0][n-1]);
	return 0;
}