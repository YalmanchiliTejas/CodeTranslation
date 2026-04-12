#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

/* short */
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORR(i, a, b) for(int i = (a); i > (b); i--)
#define REP(i, n) for(int i = 0; i < (n); i++)

/* exchange */
#define chmin(a, b) (a) = min((ll)(a), (ll)(b))
#define chmax(a, b) (a) = max((ll)(a), (ll)(b))

/* output */
#define IN(x) cin >> x
#define DE(x) cerr << (x) << " "
#define BR cerr << "\n"
#define OUT(x) cout << (x) << endl
#define FIX cout << fixed << setprecision(10)

/* const */
const int ARRAY = 100005;
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;

ll N = 0;
ll ret = 0;

int main(void){
  
  IN(N);

  OUT((N>=30)?"Yes":"No");

}
