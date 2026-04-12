#include <bits/stdc++.h>
#define N 100009
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define LL long long
// ios::sync_with_stdio(false);
using namespace std;
int n, cnt;
int a[N], b[N], len[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        b[i] = a[n - i + 1];
    len[++cnt] = b[1];
    for (int i = 2; i <= n; i++)
    {
        int p = upper_bound(len + 1, len + 1 + cnt, b[i]) - len;
        if (p > cnt)
            cnt++;
        len[p] = b[i];
    }
    cout << cnt << endl;
    return 0;
}
