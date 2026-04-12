// 16:07
#define DEBUG 1
#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
#define all(v) (v).begin(), (v).end()
#define for1(i, n) for (ll i = 0; i < (n); i++)
#define for2(i, m, n) for (ll i = (m); i < (n); i++)
#define for3(i, m, n, d) for (ll i = (m); i < (n); i += (d))
#define rfor1(i, n) for (ll i = 0; i > (n); i--)
#define rfor2(i, m, n) for (ll i = (m); i > (n); i--)
#define rfor3(i, m, n, d) for (ll i = (m); i > (n); i += (d))
#define INF (1LL << 60)
#if DEBUG
#define dump(v1) dump_1(#v1, v1)
#define dump2(v1, v2) dump_2(#v1, v1, #v2, v2)
#define dump3(v1, v2, v3) dump_3(#v1, v1, #v2, v2, #v3, v3)
#define dump4(v1, v2, v3, v4) dump_4(#v1, v1, #v2, v2, #v3, v3, #v4, v4)
#else
#define dump(v1)
#define dump2(v1, v2)
#define dump3(v1, v2, v3)
#define dump4(v1, v2, v3, v4)
#endif
#if DEBUG
template <typename T>
void dump_1(const string& n1, const T& v1)
{
    cerr << n1 << ": " << v1 << endl;
}
template <typename T1, typename T2>
void dump_2(const string& n1, const T1& v1, const string& n2, const T2& v2)
{
    cerr << n1 << ": " << v1 << "  " << n2 << ": " << v2 << endl;
}
template <typename T1, typename T2, typename T3>
void dump_3(const string& n1, const T1& v1, const string& n2, const T2& v2,
            const string& n3, const T3& v3)
{
    cerr << n1 << ": " << v1 << "  " << n2 << ": " << v2 << "  " << n3 << ": "
         << v3 << endl;
}
template <typename T1, typename T2, typename T3, typename T4>
void dump_4(const string& n1, const T1& v1, const string& n2, const T2& v2,
            const string& n3, const T3& v3, const string& n4, const T4& v4)
{
    cerr << n1 << ": " << v1 << "  " << n2 << ": " << v2 << "  " << n3 << ": "
         << v3 << "  " << n4 << ": " << v4 << endl;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& v)
{
    os << "(" << v.first << ", " << v.second << ")";
    return os;
}
template <typename T1, typename T2, typename T3>
ostream& operator<<(ostream& os, const tuple<T1, T2, T3>& v)
{
    os << "(" << get<0>(v) << ", " << get<1>(v) << ", " << get<2>(v) << ")";
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << " ";
        }
        os << *it;
    }
    return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v)
{
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << " ";
        }
        os << *it;
    }
    return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const map<T1, T2>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ", ";
        }
        os << it->first << ":" << it->second;
    }
    os << "}";
    return os;
}
#endif  // DEBUG
void Yes(void) { cout << "Yes" << endl; }
void No(void) { cout << "No" << endl; }
void YES(void) { cout << "YES" << endl; }
void NO(void) { cout << "NO" << endl; }
template <typename T>
void print(const T& v)
{
    cout << v << endl;
}
//---------------------------------------------------------
void dfs(ll pos, ll N, vvll& to, ull visited, ll& ans)
{
    if ((visited >> pos) & 1) {
        return;
    }
    visited |= (1 << pos);
    if (visited + 1 == (1u << (N))) {
        ans++;
        return;
    }
    for (ll t : to[pos]) {
        dfs(t, N, to, visited, ans);
    }
}
void solve()
{
    ll ans = 0;
    ll N, M;
    cin >> N >> M;
    vvll to(N);
    for1 (i, M) {
        ll a, b;
        cin >> a >> b;
        --a;
        --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0, N, to, 0, ans);
    print(ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
