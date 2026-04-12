#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){ 
  ll n, x, m;
  cin >> n >> x >> m;
  map<ll, ll>vis;
  queue<ll>q;
  ll cx = x, loop = 0, sum = 0;
  vis[x] = 1;
  for(ll i = 1; i <= m; i++) {
    q.push(x);
    sum += x;
    x = x * x % m;
    if(vis[x] != 0) {
      loop = x;
      break;
    }
    vis[x] = 1;
    if(x == 0) {
      cout << sum << endl;
      return;
    }
  }
  ll lsum = 0, lpos = 0;
  while(q.front() != loop) {
    lsum += q.front();
    q.pop();
    lpos++;
  }
  ll ans = lsum, qsize = (ll) q.size();
  n -= lpos;
  sum -= lsum;
  ans += sum * (n/qsize);
  n %= qsize;
  ll i = 0;
  while(n--) {
    ans += q.front();
    q.pop();
  }
  cout << ans << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
