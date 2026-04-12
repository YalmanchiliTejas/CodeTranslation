#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream& operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream& operator<<(ostream &os, vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream& operator<<(ostream &os, set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream& operator<<(ostream &os, unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream& operator<<(ostream &os, multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream& operator<<(ostream &os, unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream& operator<<(ostream &os, map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream& operator<<(ostream &os, unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

lint N, X;
vector<lint> sz(52);
vector<lint> whole(52);

lint cou(lint l, lint x)
{
    if (l == 0 && x == 1) return 1;
    if (x <= 1) return 0;
    x--;
    lint ans = 0;
    if (x >= sz[l - 1])
    {
        ans += whole[l - 1];
        x -= sz[l - 1];
        if (x == 0) return ans;
        ans += 1;
        x--;
    }
    return ans + cou(l - 1, min(x, sz[l - 1]));
}

int main()
{
    cin >> N >> X;

    sz[0] = 1;
    REP(i, N + 1) sz[i + 1] = sz[i] * 2 + 3;
    whole[0] = 1;
    REP(i, N + 1) whole[i + 1] = whole[i] * 2 + 1;
    cout << cou(N, X) << endl;
}
