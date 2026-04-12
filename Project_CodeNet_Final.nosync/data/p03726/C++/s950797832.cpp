#include <bits/stdc++.h>
#define int long long
#define ll long long
using ull = unsigned long long;
using namespace std;
const int INF = 1ll << 50;
const int MOD = 1e9 + 7;
#define dump(x)                             \
    if (dbg) {                              \
        cerr << #x << " = " << (x) << endl; \
    }
#define overload4(_1, _2, _3, _4, name, ...) name
#define FOR1(n) for (ll i = 0; i < (n); ++i)
#define FOR2(i, n) for (ll i = 0; i < (n); ++i)
#define FOR3(i, a, b) for (ll i = (a); i < (b); ++i)
#define FOR4(i, a, b, c) for (ll i = (a); i < (b); i += (c))
#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define FORR(i, a, b) for (int i = (a); i <= (b); ++i)
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return 1;
    } else
        return 0;
}
template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    } else
        return 0;
}
void Yes(bool flag = true) {
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
void No(bool flag = true) {
    Yes(!flag);
}
void YES(bool flag = true) {
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
void NO(bool flag = true) {
    YES(!flag);
}
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(), (v).end()
#define SZ(x) ((int)(x).size())
#define vi vector<int>
//#define P pair<int, int>
//#define V vector<int>
//#define S set<int>
#define itn int
#define asn ans
bool dbg = false;

int N;
vector<vi> G;
int used[101010];
int Size[101010];

void solve() {
    queue<int> que;
    FOR(N) {
        if (G[i].size() == 1)
            que.push(i);
        Size[i] = G[i].size();
    }
    while (!que.empty()) {
        int idx = que.front();
        que.pop();
        if (used[idx])
            continue;
        used[idx] = 1;
        if (Size[idx] == 0) {
            cout << "First" << endl;
            return;
        }
        int nxt;
        for (auto& tmp : G[idx]) {
            if (!used[tmp]) {
                nxt = tmp;
                used[tmp] = 1;
                break;
            }
        }
        for (auto& v : G[nxt]) {
            Size[v]--;
            if (!used[v] && Size[v] <= 1)
                que.push(v);
        }
    }
    cout << "Second" << endl;
    return;
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> N;
    G.resize(N);
    FOR(N - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].pb(b);
        G[b].eb(a);
    }


    solve();
    return 0;
}
