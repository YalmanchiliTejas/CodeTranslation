#include <bits/stdc++.h>
#define VI vector<int>
#define VVI vector<vector<int>>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define INF 1e9
#define All(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) cin >> A[i];
  vector<int> w, h;
  for (int i = 0; i < H;i++){
    bool flag = true;
    for (int j = 0; j < W;j++){
      if(A[i][j]=='#')
        flag = false;
    }
    if(flag)
      h.push_back(i);
  }
  for (int i = 0; i < W;i++){
    bool flag = true;
    for (int j = 0; j < H;j++){
      if(A[j][i]=='#')
        flag = false;
    }
    if(flag)
      w.push_back(i);
  }

  int widx = 0, hidx = 0;
  for (int i = 0; i < H; i++) {
    if(hidx<h.size()&&i==h[hidx]){
      hidx++;
      continue;
    }
    widx = 0;
    for (int j = 0; j < W; j++) {
      if(widx<w.size()&&j==w[widx]){
      widx++;
      continue;
      }
      cout << A[i][j];
    }
    cout << endl;
  }

    return 0;
}
