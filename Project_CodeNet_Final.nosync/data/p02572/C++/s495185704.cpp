#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define SZ(a) (int)((a).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> Pii;
typedef pair <ll, int> Pli;
typedef unsigned long long ull;
const double eps = 1e-8;
const int mod = (int)(1e9) + 7;
const int inf = 0x7fffffff;
const int N = (int)(2e5) + 7;

int n;
ll a[N], pre[N];

int main() {

    // freopen("in.in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        pre[i] = (pre[i - 1] + a[i]) % mod;
    }
    ll res = 0;
    for (int i = 2; i <= n; ++i) {
        res = (res + a[i] * pre[i - 1] % mod) % mod;
    }
    printf("%lld\n", res);

    return 0;
}