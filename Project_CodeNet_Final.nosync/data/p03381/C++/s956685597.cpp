#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>


using namespace std;
#define INF 0x3f3f3f3f3f
#define ll long long
#define pr(x) (cerr << #x << ' ' << x << ' ')
#define prln(x) (cerr << #x << ' ' << x << endl)
const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];

int main()
{
	#ifdef LOCAL
		freopen("in.txt", "r", stdin);
	#endif // LOCAL

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	int m = n / 2;

	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; ++i) {
		if (b[i] <= a[m]) {
			printf("%d\n", a[m + 1]);
		}else {
			printf("%d\n", a[m]);
		}
	}

	return 0;
}