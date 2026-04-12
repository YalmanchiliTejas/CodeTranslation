#include <bits/stdc++.h>

#define rep(i, n)     for(int i = 0;      i < int(n); ++i)
#define rep3(i, a, b) for(int i = int(a); i < int(b); ++i)
#define all(x)        (x).begin(),(x).end()
#define sz(x)         int(x.size())
#define mp            make_pair
#define pb            push_back


typedef long long ll;

using namespace std;

int main(){
  int H, W;
  cin >> H >> W;

  vector<string> grid;
  rep(h, H){
    string s;
    cin >> s;
    if(s.find("#") != string::npos){
      grid.pb(s);
    }
  }

  rep(w, sz(grid[0])){
    bool delete_flag = true;
    rep(h, sz(grid)){
      if(grid[h][w] == '#'){
        delete_flag = false;
        break;
      }
    }
    if(delete_flag){
      rep(h, sz(grid)){
        string s = grid[h];
        s.erase(w, 1);
        grid[h] = s;
      }
      w--;
    }
  }

  rep(h, sz(grid)){
    cout << grid[h] << endl;
  }


  return 0;
}
