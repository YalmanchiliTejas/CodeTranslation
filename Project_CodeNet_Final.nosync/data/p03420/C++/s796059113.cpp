# include <bits/stdc++.h>

using namespace std;
typedef long long i64;

const int INF = 1000000000;
const int N = 100005;


int main ()
{
    i64 n, k, ans = 0;
    cin >> n >> k;
    for (i64 i = 1; i <= n; ++i) {
        i64 m = n % i;
        ans += (n - m) / i * max(i - k, 0ll) + max(m - k + 1, 0ll);
        //printf("%lld\n", (n - m) / i * max(i - k, 0ll) + max(m - k + 1, 0ll));
    }
    if (k == 0) ans -= n;
    printf("%lld\n", ans);
    return 0;
}
