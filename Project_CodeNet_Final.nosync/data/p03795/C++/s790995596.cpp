#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define TMP 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", n * 800 - n / 15 * 200);
	return 0;
} 