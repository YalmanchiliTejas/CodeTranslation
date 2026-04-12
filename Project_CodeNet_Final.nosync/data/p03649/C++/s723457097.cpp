#include <bits/stdc++.h>

#define ll long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define vi vector<int>
using namespace std;
int mod = 1'000'000'000 + 7;
namespace uf {
    vector<int> par, rank;

    void init(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        } else {
            return par[x] = root(par[x]);
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)return;
        if (rank[x] < rank[y]) {
            par[x] = y;
        } else {
            par[y] = x;
            if (rank[x] == rank[y])rank[x]++;
        }
    }
}
namespace choose {
    vector<vector<ll>> v;
    vector<ll> vv;

    void init_simple(int N) {
        vv.resize(1);
        vv[0] = 1;
        v.push_back(vv);
        for (int i = 1; i <= N; i++) {
            vv.resize(i + 1);
            for (int j = 1; j < i; j++) {
                vv[j] = v[i - 1][j - 1] + v[i - 1][j];
            }
            vv[i] = 1;
            v.push_back(vv);
        }
    }

    ll simple(int p, int q) {
        return v[p][q];
    }
}
namespace prime {
    vector<bool> is_not_prime{1, 1, 0};

    void make_is_not_prime(int N) {
        int l = is_not_prime.size();
        if (l >= N + 1) {
            return;
        }
        is_not_prime.resize(N + 1);
        for (int i = 2; i <= N; i++) {
            if (!is_not_prime[i]) {
                for (int j = max(((l + i - 1) / i) * i, i + i); j <= N; j += i) {
                    is_not_prime[j] = 1;
                }
            }
        }
    }

    vector<ll> list(ll a, ll b) {
        //{a, b)
        a = max(2LL, a);
        set<ll> st;
        for (ll i = a; i < b; i++) {
            st.insert(i);
        }
        ll l = sqrt(b);
        make_is_not_prime(l);
        for (ll i = 2; i <= l; i++) {
            if (!is_not_prime[i]) {
                for (ll j = max(((a + i - 1) / i) * i, i + i); j < b; j += i) {
                    st.erase(j);
                }
            }
        }
        vector<ll> res;
        for (auto x:st) {
            res.push_back(x);
        }
        return res;
    }
}

ll pow_mod(ll n, ll k, ll m) {
    ll r = 1;
    for (; k > 0; k >>= 1) {
        if (k & 1) r = (r * n) % m;
        n = (n * n) % m;
    }
    return r;
}

ll Manhattan(ll a, ll b, ll c, ll d) {
    return abs(a - c) + abs(b - d);
}

ll Manhattan(pair<ll, ll> a, pair<ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll gcd(ll a, ll b) {
    if (b == 0)return a;
    return gcd(b, a % b);
} // C++17
void COME_LET_THE_GAMES_BEGIN() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
}

int N;
ll a[50];

int main() {
    COME_LET_THE_GAMES_BEGIN();
    cin >> N;
    rep(i, N)cin >> a[i];
    ll ans = 0;
    while (1) {
        bool f = 1;
        for (int i = 0; i < N; i++) {
            if (N - 1 < a[i]) {
                ll x = (a[i] - (N - 1)) / N;
                a[i] -= x * N;
                if (N - 1 < a[i]) {
                    x++;
                    a[i] -= N;
                }
                for (int j = 0; j < N; j++) {
                    if (i != j) {
                        a[j] += x;
                    }
                }
                ans += x;
                f = 0;
            }
        }
        if (f) {
            break;
        }
    }
    cout << ans << endl;
}