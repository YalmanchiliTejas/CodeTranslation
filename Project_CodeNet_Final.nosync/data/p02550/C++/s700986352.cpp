#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define pb push_back
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()

typedef pair<int, int> P;

const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

//------------------------------------------------------//


int main(){
  ll n, x, m;
  cin >> n >> x >> m;
  vec<int> id(m, -1);
  vec<int> a;
  int len = 0;
  ll tot = 0;
  while(id[x] == -1){
    a.pb(x);
    id[x] = len;
    len++;
    tot += x;
    x = (x * x) % m;
  }

  int c = len - id[x];
  ll s = 0;
  repc(i, id[x], len-1) s += a[i];

  ll ans = 0;
  if(n <= len){
    rep(i, n) ans += a[i];
  }
  else{
    ans += tot;
    n -= len;
    ans += s*(n/c);
    n %= c;
    rep(i, n) ans += a[id[x]+i];
  }
  cout << ans << endl;
  return 0;
}