#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  int H, W; cin >> H >> W;
  vector<string> field(H);
  rep(i, H) cin >> field[i];

  vector<string> tmp;
  bool flag;
  rep(i, H){
    flag = false;
    rep(j, W) if (field[i][j] == '#') flag = true;
    if (flag) tmp.push_back(field[i]);
  }
  vector<string> ans((int)tmp.size());
  rep(j, W){
    flag = false;
    rep(i, (int)tmp.size()) if (tmp[i][j] == '#') flag = true;
    if (flag) {

      rep(i, (int)tmp.size()) ans[i].push_back(tmp[i][j]);
    }
  }

  rep(i, (int)ans.size()){
    rep(j, (int)ans[i].size()) cout << ans[i][j];
    cout << endl;
  }
}
