#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X,i) ((X>>i)&1)
#define REP(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define SORT(a) sort(all(a))
#define RSORT(a) sort(rall(a))
#define ina(x,n) rep(x_i,n) cin>>x[x_i]
#define outa(x,n) rep(x_i,n) cerr<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;

const int MOD = 1e9+7;
const int INF = (1<<28);
const ll INFL = (1LL<<60);

int main() {
  int n, m; cin >> n >> m;
  cout << (n==m?"Yes":"No") << endl;
  return 0;
}
