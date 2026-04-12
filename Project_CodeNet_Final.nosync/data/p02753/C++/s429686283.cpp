#include <bits/stdc++.h>
using namespace std;

//////////////////////////////   Begin Macros

#define ALL(x) (x).begin(), (x).end()
#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (int i = 1; i <= N; i++)
const int intinf = numeric_limits<int>::max();
#define MOD 1000000007

using ll = long long int;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &m, const T q)
{
    if (m < q)
    {
        m = q;
        return true;
    }
    else
        return false;
}
template <typename T>
bool chmin(T &m, const T q)
{
    if (m > q)
    {
        m = q;
        return true;
    }
    else
        return false;
}
template <typename T1, typename T2>
pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first + r.first, l.second + r.second}; }
template <typename T1, typename T2>
pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return {l.first - r.first, l.second - r.second}; }
template <typename T>
istream &operator>>(istream &is, vector<T> &vec)
{
    for (auto &v : vec)
        is >> v;
    return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
    os << "[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const deque<T> &vec)
{
    os << "deq[";
    for (auto v : vec)
        os << v << ",";
    os << "]";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &vec)
{
    os << "{";
    for (auto v : vec)
        os << v << ",";
    os << "}";
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &pa)
{
    os << "(" << pa.first << "," << pa.second << ")";
    return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const map<TK, TV> &mp)
{
    os << "{";
    for (auto v : mp)
        os << v.first << "=>" << v.second << ",";
    os << "}";
    return os;
}
template <typename TK, typename TV>
ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp)
{
    os << "{";
    for (auto v : mp)
        os << v.first << "=>" << v.second << ",";
    os << "}";
    return os;
}

template <typename T>
void reset(vector<T> &v, const T reset_to)
{
    for (auto &x : v)
        x = reset_to;
}
inline int popcount(const unsigned int x) { return __builtin_popcount(x); }

#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

//////////////////////////////   End Macros

void solve()
{
    string S;
    cin >> S;
    if (S[0] != S[1] or S[1] != S[2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    solve();
    return 0;
}
