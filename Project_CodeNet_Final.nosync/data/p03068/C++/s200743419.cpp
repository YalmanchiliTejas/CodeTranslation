#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* short */
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define ALL(v) begin(v), end(v)
#define RALL(v) rbegin(v), rend(v)

/* REPmacro */
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) for(int i = 0; i < (n); i++)
#define EACH(begin, end) for(auto itr = (begin); itr != (end); itr++)

/* function */
#define IN(x) cin >> x
#define DEBUG(x) cerr << (x) << " "
#define PRINT(x) cout << (x) << endl
#define BR cout << endl

/* const */
const int INF = 1001001001; // 10^9
const ll LINF = 1001001001001001001; // 10^18
const int MOD = 1e9 + 7;



ll N = 0;
string S;
ll K = 0;
ll ret = 0;

void input() {
  IN(N);
  IN(S);
  IN(K);
}

void solve() {
  char c = S[K-1];
  for (ll i = 0; i<N; i++) {
    char out = S[i];
    if (c != out) {
      out = '*';
    }
    cout << out;
  }
  cout << endl;
}

int main(void){
  input();
  solve();
}
