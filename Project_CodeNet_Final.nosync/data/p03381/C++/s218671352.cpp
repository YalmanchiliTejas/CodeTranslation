#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN (1000000 + 5)
#define pii pair<int, int>
using namespace std;
int n, ans[MAXN];
pii a[MAXN];
int main()
{
//    cout << "Hello world!" << endl;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].first), a[i].second = i;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		ans[a[i].second] = ((i > (n >> 1)) ? a[n >> 1].first : a[(n >> 1) + 1].first);
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
    return 0;
}

// 2 4 4 3
// 2 3 4 4
