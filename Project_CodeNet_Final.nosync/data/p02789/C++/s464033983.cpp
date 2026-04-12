#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e7 + 1;
const long long MOD = 1000000007;
const long double PI = 3.14159265;

#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); ++i)
#define RFOR(i,n,r) for(ll i = (ll)(n-1); i >= r; --i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n,0)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()

#define cout cout << setprecision(12)

using ll = long long int;
using ull = unsigned long long int;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using vp = vector<pair<ll, ll>>;
using vs = vector<string>;
using vc = vector<char>;
using lst = list<ll>;
using pq = priority_queue<ll>;

template < typename T >
inline void dbg(T a) { cout << a << ' '; }

ll n, m, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

/*--------------------template--------------------*/

int main() {
    cin >> n >> m;
    if (n==m)
    cout << "Yes" << endl;
    else
      dbg("No");
}
