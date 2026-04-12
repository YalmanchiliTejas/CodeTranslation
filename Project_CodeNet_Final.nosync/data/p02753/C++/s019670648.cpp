#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream> 
#include <cmath>
#include <map>
#include <queue>
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
const ll MOD=ll(1e9+7);
const ll INF = ll(1e18) + 7;
 
//repetition
#define REP(i,n)  for(ll i=0;i<n;i++)
#define RREP(i,n)  for(ll i=n;i != 0;i--)
 
ll P_POW(ll i, ll n) {
  if(n==0) return 1;
 
  n--;
  ll rep = i;
 
  while(n) {
    rep = rep * i;
    n--;
  }
  return rep;
} 
 
unsigned GetDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}
 
unsigned binarySearch(ll target, ll max, ll min) {
  while((max - min) > 1) {
      if((max + min)/2 > target) {
        max = (max + min)/2;
        min = min;
      } else {
        max = max;
        min = (max + min)/2;
      }
    }
}
 
void f(int rest, string s) {
  char abc[] = "abc";
  if(rest == 0) {
    cout << s << endl;
  } else {
    for(int i=0; i < 3; i++) {
      f(rest - 1, s+abc[i]);
    }
  }
} 
 
 
 
// origin (ox, oy) destination (dx, dy)
//
/*
ll dfs2(ll ox, ll oy, vector<vector<char>> v, vector<vector<int>> dist) {
 
  int m = 0;
  for (int i = 0; i < 4; i++) {
    int nx = ox+dx[i], ny = oy + dy[i];
    if(nx < 0 || nx >= w || ny < 0 || nx >= h) continue;
    if(v[nx][ny] != '.') continue;
 
    if(dist[nx][ny] == -1) {
      dist[nx][ny] = dist[ox][oy] + 1;
 
      dist[nx][ny] = min(dist[ox][oy], dist[nx][ny]);
 
      cout << "v[nx][ny]: " << dist[nx][ny] << endl;
      cout << "dx: " << dx << endl;
      cout << "dy: " << dy << endl;
      cout << "v[ox][oy]: " << v[ox][oy] << endl;
      cout << "(nx, ny)" << "("<< nx << "," << ny << ")"<< endl;
      dfs2(nx, ny, v, dist);
    }
    m = max(m, dist[nx][ny]);
  }
  return m;
}
 
int main() {
  // vector<vector<ll>> a(n ,vector<ll>{2,0});
  // vector
  // vector<ll> s(n,0);
  // vector<vector<ll>> v;
  // map<ll,ll> m;
  // priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  // vector<pair<ll, ll>> epv(n, {0, 0});
  // vector<vector<char>> v(h, vector<char>(w));
  
  for(auto&& m: em) {
    epv.push_back({ m.second, m.first });
  }
 
  ll n, k, a;
  cin >> n >> k;
 
  vector<ll> vp;
  vector<ll> vn;
 
  ll c = 0;
 
  REP(i, n) {
    cin >> a;
    if(a >= 0 ) vp.push_back(a);
    else vn.push_back(a);
  }
 
  sort(vp.begin(), vp.end());
  sort(vn.begin(), vn.end());
 
  ll ps = vp.size();
  ll ns = vn.size();
 
  cout << "k: " << k << endl;
  cout << "ps: " << ps << endl;
  cout << "ns: " << ns << endl;
 
  if(k < ps * ns) {
    ll m = k%ns;
    ll d = k - (m+1);
    cout << vn[m] * vp[d] << endl;
 
  }else {
    ll kd = k - ps*ns;
    ll md = kd%ps;
    ll dd = kd - md;
 
 
    ll s = 0;
    REP(i, ps) {
      s = s+(ps-i-1);
      cout << "s: " << s << endl;
      cout << "kd: " << kd << endl;
      cout << "s: " << s << endl;
      cout << "kd: " << kd << endl;
      cout << "i: " << i << endl;
      if(s > kd) {
        cout << "vp[i]: " << vp[i] << endl;
        cout << "vp[ps-i]: " << vp[s-kd+i-1] << endl;
        cout << vp[i] * vp[s-kd+i-1] << endl;
        break;
      }
    }
  }
 
}
 
*/
 
ll h, w;
vector<vector<char>> v;
 
vector<ll> dx = {-1, 0, 1, 0};
vector<ll> dy = {0, -1, 0, 1};
 
ll bfs(ll ox, ll oy) {
  //cout << "w: " << w << endl;
  //cout << "h: " << h << endl;
  vector<vector<ll>> vd(h, vector<ll>(w, -1));
  queue<pair<ll, ll>> q;
  q.push({ox, oy});
  vd[oy][ox] = 0;
 
  ll res = 0;
  while(!q.empty()) {
    pair<ll, ll> vn = q.front();
    q.pop();
    res = max(res, vd[vn.second][vn.first]);
 
    for(ll i = 0; i < 4; i++){
      ll nx = vn.first +dx[i];
      ll ny = vn.second + dy[i];
 
      /*
      cout << "----" << endl;
      cout << "nx: " << nx << endl;
      cout << "ny: " << ny << endl;
      */
 
      if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if(v[ny][nx] == '#') continue;
      if(vd[ny][nx] == -1) {
        vd[ny][nx] = res + 1;
        q.push({nx, ny});
      }
    }
  }
  return res;
}
 
int main() {
  string s;
  cin >> s;

  if(s == "AAA") {
    cout << "No";
  } else if(s == "BBB") {
    cout << "No";
  } else {
    cout << "Yes";
  }
}
