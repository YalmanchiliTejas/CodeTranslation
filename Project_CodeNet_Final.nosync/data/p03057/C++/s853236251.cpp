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
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
#define FI first
#define SE second
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))

constexpr lint MOD = 1000000007;

lint corner_case(int N)
{
    lint a = 1, b = 0; // R始まり
    lint c = 0, d = 1; // B始まり
    REP(i, N - 1)
    {
        lint bnew = a;
        lint anew = (a + b) % MOD;
        a = anew;
        b = bnew;

        lint dnew = c;
        lint cnew = (c + d) % MOD;
        c = cnew;
        d = dnew;
    }
    return (a + b + c) % MOD;
}

int main()
{
    lint N;
    cin >> N;
    lint M;
    cin >> M;
    string S;
    cin >> S;
    if (S[0] == 'B')
    {
        for (auto &c : S)
        {
            c = 'R' + 'B' - c;
        }
    }
    int n = 0;
    vector<int> con;
    for (auto c : S)
    {
        if (c == 'R') n++;
        else con.push_back(n), n = 0;
    }
    if (con.size() == 0)
    {
        lint ret = corner_case(N);
        cout << ret << endl;
        return 0;
    }

    if (N % 2)
    {
        cout << 0 << endl;
        return 0;
    }

    int Lmaxi = (con[0] % 2 ? con[0] : con[0] + 1);
    FOR(i, 1, con.size())
    {
        if (con[i] % 2) mmin(Lmaxi, con[i]); // 奇数だとヤバい
    }

    int P = (Lmaxi + 1) / 2;
    int Q = N / 2;
    // QをP以下で分割

    vector<lint> dp(Q + 1);
    dp[0] = 1;
    lint acc = dp[0];
    REP(i, Q)
    {
        dp[i + 1] = acc;
        (acc += dp[i + 1]) %= MOD;
        if (i + 1 - P >= 0) (acc += MOD - dp[i + 1 - P]) %= MOD;
    }

    vector<lint> dp_acc(Q + 2);
    REP(i, Q + 1) dp_acc[i + 1] = (dp_acc[i] + dp[i]) % MOD;

    lint ret = 0;
    REP(l, Lmaxi + 1)
    {
        int n = l / 2;
        if (n < P) (ret += (dp_acc[max(Q - n, 0)] - dp_acc[max(Q - P, 0)] + MOD)) %= MOD;
    }
    cout << ret << endl;
}
