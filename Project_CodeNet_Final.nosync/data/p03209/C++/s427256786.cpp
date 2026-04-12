#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,n) for(int i = 1; i < n; i++)
#define repll(i,n) for(ll i = 0; i < n; i++)
#define REPll(i,n) for(ll i = 1; i < n; i++)
#define sz(x) int(x.sze())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yesorno(a) printf(a ? "yes\n" : "no\n")
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define YESorNO(a) printf(a ? "YES\n" : "NO\n") 
#define endl "\n"
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

long long sze[55] = {};

ll f(ll n, ll x) {
  if(n == 0) return 1;
  else if(x == 1) return 0;
  else if(x >= 2 && x <= sze[n]/2) return f(n-1,x-1);
  else if(x-1 == sze[n]/2) return f(n-1, x-2) + 1;
  else if(x > sze[n]/2+1 && x < sze[n]-1) return f(n-1, x-sze[n]/2-1) + f(n-1,sze[n]/2-1) +1;
  else return f(n-1, sze[n]/2-1)*2 +1;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n, x;
  cin >> n >> x;
  sze[0] = 1;
  REP(i,n+1) {
    sze[i] = sze[i-1]*2 + 3;
  }

  //cout << s[n] << endl;
  ll ans = f(n, x);
  cout << ans << endl;
}