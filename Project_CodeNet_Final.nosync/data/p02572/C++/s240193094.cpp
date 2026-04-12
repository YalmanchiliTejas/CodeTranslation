#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

ll MOD = 1000000007;

int main(){

  ios_base::sync_with_stdio (false);
  cin.tie(NULL);
  ll N;
  cin >> N;
  vl arr = vl(N, 0);
  vl sums = vl(N, 0);
  FOR(i, 0, N) cin >> arr[i];
  FORD(i, 0, N-1) sums[i] = (sums[i+1]+arr[i+1])%MOD;

  ll sol = 0;
  FOR(i, 0, N) sol=(sol+(arr[i]*sums[i])%MOD)%MOD;

  cout << sol << endl;
}
