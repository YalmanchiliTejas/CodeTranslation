#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;

/*
  先に縦と横 それぞれに走査して，黒のマスがある場所をチェックする
  その後，両方ともチェックがある場所のみ出力すると楽

*/

int main(){
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  REP(h,H){
    string s;
    cin >> s;
    field[h] = s;
  }

  vector<bool> tate(H, false);
  vector<bool> yoko(W, false);

  REP(h,H){
    bool ok = false;
    REP(w,W){
      if(field[h][w] == '#'){
        ok = true;
        break;
      }
    }
    tate[h] = ok;
  }


  REP(w,W){
    bool ok = false;
    REP(h,H){
      if(field[h][w] == '#'){
        ok = true;
        break;
      }
    }
    yoko[w] = ok;
  }

  //Output

  REP(h,H){
    bool ok = false;
    REP(w,W){
      if(tate[h] && yoko[w]){
        cout << field[h][w];
        ok = true;
      }
    }
      if(ok) cout << endl;
    }

  return 0;
}
