# include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;
typedef long long i64;

int a[N], b[N];

int main ()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), b[i] = a[i];
    sort(b + 1, b + n + 1);
    int t1 = b[n / 2], t2 = b[n / 2 + 1];
    for (int i = 1; i <= n; ++i) {
        if (a[i] > t1) printf("%d\n", t1);
        else printf("%d\n", t2);
    }
    return 0;
}
