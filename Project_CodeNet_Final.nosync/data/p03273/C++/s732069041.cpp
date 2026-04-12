#include <bits/stdc++.h>
using namespace std;

#define int long long
#define For(i, a, b) for (int i = (a); i <= static_cast<int>(b); i++)
#define Forr(i, a, b) for (int i = (a); i >= static_cast<int>(b); i--)
#define rep(i, n) For(i, 0, n - 1)
#define repall(i, arr) for (auto& i : (arr))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define dump(x) cerr << #x << " = " << (x) << '\n'

template <typename T>
using pq = priority_queue<T>;
template <typename T>
using pqr = priority_queue<T, vector<T>, greater<T>>;
const int INF = INT_MAX / 2;
constexpr int MOD = 1e9 + 7;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vec>;

template <typename T1, typename T2>
ostream& operator<<(ostream& stream, const pair<T1, T2>& p) {
    return stream << p.first << " " << p.second;
}
template <typename T>
void print(const vector<vector<T>> matrix) {
    repall (vec, matrix)
        print(vec);
}
template <typename T>
void print(const vector<T> vec) {
    unsigned int len = vec.size();
    rep (i, len - 1)
        cout << vec[i] << ' ';
    cout << vec[len - 1] << '\n';
}
template <typename Arg>
void print(const Arg arg) {
    cout << arg << '\n';
}
template <typename Head, typename... Args>
void print(const Head head, const Args... args) {
    cout << head << " ";
    print(args...);
}
template <typename T>
T sum_(vector<T> vec, T init = 0) {
    return std::accumulate(all(vec), T(init));
}

void yn(bool tf) { print(tf ? "Yes" : "No"); }
void YN(bool tf) { print(tf ? "YES" : "NO"); }

template <typename T>
void init(vector<T>& v) {
    rep (i, v.size())
        cin >> v[i];
}

template <typename T, typename U>
void init(vector<T>& v, vector<U>& w) {
    assert(v.size() == w.size());
    rep (i, v.size())
        cin >> v[i] >> w[i];
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

// -------------------------------------------------------------------
// sort 1 2 3 4

signed main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> delh(h);
    vector<bool> delw(w);

    rep (i, h)
        init(a[i]);

    rep (i, h) {
        bool all = true;
        rep (j, w)
            if (a[i][j] == '#') {
                all = false;
                break;
            }
        delh[i] = all;
    }

    rep (j, w) {
        bool all = true;
        rep (i, h)
            if (a[i][j] == '#') {
                all = false;
                break;
            }
        delw[j] = all;
    }

    rep (i, h) {
        rep (j, w)
            if (!delh[i] and !delw[j]) cout << a[i][j];
        if (!delh[i]) cout << '\n';
    }

    return 0;
}