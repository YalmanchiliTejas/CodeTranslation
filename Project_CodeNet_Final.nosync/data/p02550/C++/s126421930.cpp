#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<queue>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int> >;
using pii = pair<int, int>;
using ppi = pair<pii, int>;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ti = clock();
  // start-----------------------------------------------
  ll n, x, m;
  cin >> n >> x >> m;
  ll now = x;
  ll s = 0,e = 0;
  vector<ll> mtop(m+1, -1);
  vector<ll> acc(m+2, 0);
  for(int i = 1; i <= m+1; i++){
    acc[i] = now + acc[i-1];
    if(mtop[now%m] >= 0){
      s = mtop[now%m];
      e = i;
      break;
    }
    mtop[now%m] = i;
    now = now * now % m;
  }

  if(n > m) cout << acc[s-1] + (acc[e] - acc[s]) * ((n-s)/(e-s)) + acc[n - (n-s)/(e-s) * (e-s)] - acc[s-1] << endl;
  else cout << acc[n] << endl;


  // end-----------------------------------------------
  // cerr << 1.0 * (clock() - ti) / CLOCKS_PER_SEC << endl;
}
