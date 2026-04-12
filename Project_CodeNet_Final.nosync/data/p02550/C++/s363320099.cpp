#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using bint = boost::multiprecision::cpp_int;
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repSE(i,s,n) for (int i = (s); i < (n); i++)
#define rrepSE(i,s,e) for (int i = (s); i > (e); i--)
#define ssort(v) sort(v.begin(), v.end())
#define gsort(v) sort(v.rbegin(), v.rend())
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
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
const int dx[4] = { 1,0, -1,0 }, dy[4] = { 0,1,0,-1 };
const int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;

int main()
{
    ll n, x, m;
    cin >> n >> x >> m;
    vector<ll> mp(m, -1);
    vector<ll> sum(m);
    sum[0] = x;
    ll a = x;
    ll i = 1;
    while(i < n) {
        ll nexta = (a*a) % m;
        mp[a] = nexta;
        if (mp[nexta] != -1) break;
        sum[i] = sum[i-1] + nexta;
        // cout << "i: " << i << ", nexta: " << nexta << ", sum: " << sum << endl;
        a = nexta;
        i++;
    }
    // cout << "i: " << i << ", sum[i-1]: " << sum[i-1] << endl;
    if (i >= n) {
        cout << sum[i-1] << endl;
        return 0;
    }
    ll ans = sum[i-1];
    a = (a*a) % m;
    vector<ll> sum2(m);
    ll rem = n - i, memo = a, j = 1;
    // cout << "memo: " << memo << endl;
    sum2[1] = a;
    while(j < rem) {
        ll nexta = (a*a) % m;
        if (nexta == memo) break;
        sum2[j+1] = sum2[j] + nexta;
        a = nexta;
        j++;
    }
    if (j == rem) {
        cout << ans + sum[j-1] << endl;
        return 0;
    }
    // cout << "j: " << j << endl;
    ll nloop = rem / j, rem2 = rem % j;
    ans += nloop * sum2[j];
    if (rem > 0) {
        ans += sum2[rem2];
    }
    cout << ans << "\n";
    return 0;
}
