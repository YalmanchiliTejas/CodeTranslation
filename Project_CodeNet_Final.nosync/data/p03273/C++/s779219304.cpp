#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;

typedef long long ll;
ll INF = 1LL << 60;

int 
main() {

  int H, W; cin >> H >> W;
  vector<vector<char>> arr(H);
  rep(i, 0, H)rep(k, 0, W){
    char tmp; cin >> tmp;
    arr[i].push_back(tmp);
  }


  vector<bool> row(H, 0);
  vector<bool> col(W, 0);
  rep(i, 0, H){
    rep(k, 0, W){
      if(arr[i][k] != '.') row[i] = true, col[k] = true;
    }
  }


  rep(i, 0, H){
    if(row[i]){
      rep(k, 0, W){
        if(col[k]) cout << arr[i][k];
      }
      cout << endl;
    }
  }
}


