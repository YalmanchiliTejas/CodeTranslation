#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 123;
const ll MOD = 1e9 + 7;

ll sq(ll x) { return x * x % MOD; }
ll qpow(ll a, ll b) { return b ? sq(qpow(a, b / 2)) * (b & 1 ? a : 1) % MOD : 1; }
ll inv(ll x) { return qpow(x, MOD - 2); }

int N, H[MAX_N];
ll F[MAX_N];

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &H[i]);
    H[0] = H[N + 1] = 1;
    F[0] = 2;
    for (int i = 1; i <= N; i++) {
        ll sum = 0; int prev = H[i + 1];
        for (int j = i; j; j--) {
            int l = max(H[j - 1], prev), r = H[j];
            if (r > l) {
                sum += r - l;
            }
            prev = min(prev, H[j]);
            (F[i] += F[j - 1] * qpow(2, sum)) %= MOD;
        }
    }
    printf("%lld\n", F[N]);
}
