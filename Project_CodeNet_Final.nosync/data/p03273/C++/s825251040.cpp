#include <bits/stdc++.h>
using namespace std;
#define REP(i,N) for(i=0;i<N;i++)
typedef long long ll;

int main(void){
  int i,j,H,W;
  cin >> H >> W;
  vector<vector<char> >v(H,vector<char>(W));
  vector<bool> erase_W(W,true);
  vector<bool> erase_H(H,true);
  REP(i,H){
    REP(j,W){
      cin >> v[i][j];
      if(v[i][j] == '#'){
        erase_W[j] = false;
        erase_H[i] = false;
      }
    }
  }
  for(i=H-1;i>=0;i--){
    if(erase_H[i]) v.erase(v.begin()+i);
  }
  for(j=W-1;j>=0;j--){
    if(erase_W[j]){
      REP(i,v.size()){
        v[i].erase(v[i].begin()+j);
      }
    }
  }
  REP(i,v.size()){
    REP(j,v[i].size()) cout << v[i][j];
    cout << endl;
  }
  return 0;
}
