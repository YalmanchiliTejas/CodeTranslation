#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;

const int N = 200003;

int a[N], n, b[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	int tmp = 0;
	for (int i = n; i > 1; i -= 2) {
		++tmp;
		b[tmp] = a[i];
		b[n - tmp + 1] = a[i - 1];
	}
	if (n & 1)
		b[tmp + 1] = a[1];
	for (int i= 1; i <= n; ++i) printf("%d ", b[i]); puts("");
	return 0;
}