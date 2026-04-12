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

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int ti = clock();
  // start-----------------------------------------------
  int x; cin >> x;
  if(x >= 30) cout << "Yes" << endl;
  else cout << "No" << endl;

  // end-----------------------------------------------
  // cerr << 1.0 * (clock() - ti) / CLOCKS_PER_SEC << endl;
}
