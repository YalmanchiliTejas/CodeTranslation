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



int main(){
  int H, W;
  cin >> H >> W;
  vector<string> field(H);
  REP(h,H){
    string s;
    cin >> s;
    field[h] = s;
  }
  vector<string> field2;
  //縦の圧縮
  REP(h,H){
    bool ok = false;
    REP(w,W){
      if(field[h][w] == '#'){
        ok = true;
        break;
      }
    }
    if(!ok) continue;
    field2.push_back(field[h]);
  }

  int H2 = field2.size();

  vector<string> field3(H2);
  REP(w,W){
    bool ok = false;
    REP(h,H2){
      if(field2[h][w] == '#'){
        ok = true;
        break;
      }
    }
    if(!ok) continue;
    REP(h,H2){
      field3[h].push_back(field2[h][w]);
    }
  }

  REP(h,field3.size()){
    cout << field3[h] << endl;
  }


  return 0;
}
