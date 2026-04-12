#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
#define REP(i, n)  for(int i = 0; i < n; ++i)
#define FOR(i, t, n)  for(ll i = t; i <= (ll)n; ++i)
struct edge {
    int from, to;
    ll cost;
};


class Eratosthenes {
public:
    vector<bool> prime;

    Eratosthenes(ll size) {
        size = max((int) sqrt(size) + 1, 101010);
        prime.resize(size, 1);
        prime[0] = 0;
        prime[1] = 0;
        for (size_t i = 2; i * i <= size; ++i)
            if (prime[i]) {
                for (size_t j = 2; i * j <= size; ++j)prime[i * j] = false;
            }
    }
};


class Combination {
    vector<ll> fac; //n!(mod M)
    vector<ll> ifac; //k!^{M-2} (mod M)
public:
    Combination(ll size) {
        fac.resize(size);
        ifac.resize(size);
        fac[0] = 1;
        ifac[0] = 1;
        for (ll i = 0; i < size; i++) {
            fac[i + 1] = fac[i] * (i + 1) % MOD;
            ifac[i + 1] = ifac[i] * mpow(i + 1, MOD - 2) % MOD;
        }
    }

    ll mpow(ll x, ll n) {
        ll ans = 1;
        while (n != 0) {
            if (n & 1) ans = ans * x % MOD;
            x = x * x % MOD;
            n = n >> 1;
        }
        return ans;
    }

    ll comb(ll a, ll b) {
        if (a == 0 && b == 0)return 1;
        if (a < b || a < 0)return 0;
        ll tmp = ifac[a - b] * ifac[b] % MOD;
        return tmp * fac[a] % MOD;
    }
};


ll GCD(ll a, ll b) {
    if (b == 0)return a;
    return GCD(b, a % b);
}

ll LCM(ll a, ll b) {
    ll gcd = GCD(a, b);
    return a / gcd * b;
}

ll t1, t2, a1, a2, b1, b2;
string s;
ll N;

int main() {
    cin >> N;
    ll ans = 0;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<>());
    ll l = 0, r = N - 1;
    vector<ll> F, G;
    REP(i, N - 1) {
        if (i % 2 == 0)F.push_back(A[l++]);
        else F.push_back(A[r--]);
    }
    ans = abs(F[0] - A[N / 2]) > abs(F[F.size() - 1] - A[N / 2]) ?
          abs(F[0] - A[N / 2]) : abs(F[F.size() - 1] - A[N / 2]);
    REP(i, F.size() - 1)ans += abs(F[i] - F[i + 1]);
 
    reverse(A.begin(), A.end());
    l = 0, r = N - 1;
    REP(i, N - 1) {
        if (i % 2 == 0)G.push_back(A[l++]);
        else G.push_back(A[r--]);
    }
    ll res = abs(G[0] - A[N / 2]) > abs(G[G.size() - 1] - A[N / 2]) ?
             abs(G[0] - A[N / 2]) : abs(G[G.size() - 1] - A[N / 2]);
    REP(i, G.size() - 1)res += abs(G[i] - G[i + 1]);
    ans = max(res, ans);

    cout << ans << endl;
    return 0;
}
