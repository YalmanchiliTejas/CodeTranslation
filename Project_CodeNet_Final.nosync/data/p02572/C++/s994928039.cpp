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

int f_dir[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}}; //↑→↓←
int e_dir[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
bool is_in_field(int y, int x, int h, int w){
  return (y >= 0 && y < h && x >= 0 && x < w);
}

#define INF 1000000007

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ti = clock();
  // start-----------------------------------------------
  ll n; cin >> n;
  vector<ll> a(n);
  vector<ll> prod(n+1, 0);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  for(int i = 0; i < n; i++){
    prod[n-1 - i] = (prod[n - i] + a[n - i - 1]) % INF;
  }
  ll ans = 0;
  for(int i = 0; i < n; i++){
    ans = (ans + prod[i+1] * a[i]) % INF;
  }
  cout << ans << endl;

  // end-----------------------------------------------
  // cerr << 1.0 * (clock() - ti) / CLOCKS_PER_SEC << endl;
}
