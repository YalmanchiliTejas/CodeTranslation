#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using ll = unsigned long long;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;
constexpr ll INF = (1LL << 30) - 1LL;
constexpr ll MOD = 1e9 + 7;
constexpr int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
template <class T>
void chmin(T &a, T b) { a = min(a, b); }
template <class T>
void chmax(T &a, T b) { a = max(a, b); }
void debug() { cerr << "ok" << endl; }
template <class T>
void printv(const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}
template <class T>
void readv(vector<T> &v) {
    for (int i = 0; i < v.size(); i++) cin >> v[i];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    V<ll> s(n), t(n), u(n), v(n);
    readv(s);
    readv(t);
    readv(u);
    readv(v);
    V<V<ll>> a(n, V<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll p = 0, q = 0;
            if (s[i] == 0) {
                p = u[i];
            } else {
                for (int k = 0; k < 64; k++) {
                    if ((u[i] >> k) & 1ULL) continue;
                    q |= (1ULL << k);
                }
            }
            if (t[j] == 0) {
                p |= v[j];
                if (p & q) {
                    cout << -1 << endl;
                    return 0;
                }
            } else {
                for (int k = 0; k < 64; k++) {
                    if ((v[j] >> k) & 1ULL) continue;
                    q |= (1ULL << k);
                    if ((p >> k) & 1ULL) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
            for (int k = 0; k < 64; k++) {
                if ((q >> k) & 1ULL) continue;
                a[i][j] |= (1ULL << k);
            }
        }
        // printv(a[i]);
    }
    V<int> co(64);
    for (int i = 0; i < n; i++) {
        if (s[i] > 0) continue;
        ll b = a[i][0];
        for (int j = 1; j < n; j++) {
            b &= a[i][j];
        }
        for (int k = 0; k < 64; k++) {
            if (((u[i] ^ b) >> k) & 1ULL) {
                int id = -1;
                for (int j = 0; j < n; j++) {
                    int f = ((v[j] >> k) & 1ULL);
                    if (t[j] == 0 && f == 0) {
                        id = j;
                        break;
                    }
                }
                if (id == -1) {
                    if (co[k]) {
                        for (int j = n - 1; j >= 0; j--) {
                            if (t[j] == 1) {
                                id = j;
                                break;
                            }
                        }
                    } else {
                        for (int j = 0; j < n; j++) {
                            if (t[j] == 1) {
                                id = j;
                                break;
                            }
                        }
                    }
                    co[k] ^= 1;
                }
                if (id == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                a[i][id] ^= (1ULL << k);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (t[i] > 0) continue;
        ll b = a[0][i];
        for (int j = 1; j < n; j++) {
            b &= a[j][i];
        }
        for (int k = 0; k < 64; k++) {
            if (((v[i] ^ b) >> k) & 1ULL) {
                int id = -1;
                for (int j = 0; j < n; j++) {
                    int f = ((u[j] >> k) & 1ULL);
                    if (s[j] == 0 && f == 0) {
                        id = j;
                        break;
                    }
                }
                if (id == -1) {
                    if (co[k]) {
                        for (int j = n - 1; j >= 0; j--) {
                            int f = ((u[j] >> k) & 1LL);
                            if (s[j] == 1) {
                                id = j;
                                break;
                            }
                        }
                    } else {
                        for (int j = 0; j < n; j++) {
                            int f = ((u[j] >> k) & 1LL);
                            if (s[j] == 1) {
                                id = j;
                                break;
                            }
                        }
                    }
                    co[k] ^= 1;
                }
                if (id == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                a[id][i] ^= (1ULL << k);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ll b = 0;
        if (s[i] == 0) {
            b = a[i][0];
        }
        for (int j = 0; j < n; j++) {
            if (s[i] == 0) {
                b &= a[i][j];
            } else {
                b |= a[i][j];
            }
        }
        if (b != u[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int j = 0; j < n; j++) {
        ll b = 0;
        if (t[j] == 0) {
            b = a[0][j];
        }
        for (int i = 0; i < n; i++) {
            if (t[j] == 0) {
                b &= a[i][j];
            } else {
                b |= a[i][j];
            }
        }
        if (b != v[j]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        printv(a[i]);
    }
}