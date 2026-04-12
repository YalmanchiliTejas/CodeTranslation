#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define countof(a) (sizeof(a)/sizeof((a)[0]))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define all(a) begin(a),end(a)
template<class T> inline void sort_uniq(T& c) { sort(all(c)); c.erase(unique(all(c)), c.end()); }
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}
template<class T> void cout_v(const vector<T>& c)
{ for (int i = 0; i < c.size(); i++) cout << c[i] << endl; }
template<class T> void cout_h(const vector<T>& c)
{ for (int i = 0; i < c.size(); i++) cout << c[i] << (i==c.size()-1?"\n":" "); }
template<class T> inline bool chmin(T& a, T b) {return a>b?a=b,true:false;}
template<class T> inline bool chmax(T& a, T b) {return a<b?a=b,true:false;}
void YES(bool f){cout<<(f?"YES":"NO")<<endl;}
#define SP << " " <<
#define FMT(a) #a<<":"<<a 
#define FMT2(a,b) #a<<":"<<a<<", "<<#b<<":"<<b 
#define FMT3(a,b,c) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c 
#define FMT4(a,b,c,d) #a<<":"<<a<<", "<<#b<<":"<<b<<", "<<#c<<":"<<c<<", "<<#d<<":"<<d 

const int MOD = 1'000'000'007;
int D;
string N;

ll dp[10001][2][100][2];

ll solve(int pos = 0, bool tight = true, ll sum = 0, bool all_zero = false)
{
    if (pos == N.size()) {
        return (!all_zero && sum % D == 0) ? 1 : 0;
    }

    int digit = N[pos] - '0';

    ll& rdp = dp[pos][tight ? 1:0][sum][all_zero ? 1:0];
    if (~rdp) return rdp;

    ll res = 0;

    for (int i = 0; i <= (tight ? digit : 9); i++) {
        res += solve(pos + 1, tight && i == digit, (sum + i) % D, i == 0 && (pos == 0 || all_zero));
    }

    return rdp = res % MOD;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);

    cin >> N >> D;

    cout << solve() << endl;
}
