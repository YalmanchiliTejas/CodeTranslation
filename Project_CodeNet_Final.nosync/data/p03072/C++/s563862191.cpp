#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-8;

int h[maxn];

int main() {
    int n, res = 0;
    scanf("%d", &n);
    for (int i = 1, f; i <= n; i++) {
        scanf("%d", &h[i]);
        f = 1;
        for (int j = 1; j < i; j++) if (h[j] > h[i]) {
            f = 0;
            break;
        }
        if (f) res++;
    }
    printf("%d\n", res);
    return 0;
}
