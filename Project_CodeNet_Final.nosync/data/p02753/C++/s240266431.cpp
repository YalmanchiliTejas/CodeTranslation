#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;

/* short */
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOREACH(x, a) for(auto x : a)

/* exchange */
#define CHMIN(a, b) (a) = min((ll)(a), (ll)(b))
#define CHMAX(a, b) (a) = max((ll)(a), (ll)(b))

/* function */
#define IN(x) cin >> x
#define DEBUG(x) cerr << (x) << " "
#define LN() cerr << "\n"
#define PRINT(x) cout << (x) << endl
#define BR cout << endl

/* const */
const int ARRAY = 100005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

ll N = 0;
ll t;
ll ret = 0;
ll A = 0, B = 0, C = 0;
string s;

void input() {
  IN(s);
}

void solve() {
  bool ok = true;
  ok &= (s[0] == s[1]);
  ok &= (s[1] == s[2]);
  ok &= (s[2] == s[0]);
  PRINT(ok?"No":"Yes");
}

int main(void){
  input();
  solve();
}
