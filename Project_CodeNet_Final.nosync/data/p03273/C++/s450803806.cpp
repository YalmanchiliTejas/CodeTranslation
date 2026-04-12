#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int h, w;
    cin >> h >> w;
  string g[h];
    for(int i=0; i<h; i++) cin >> g[i];
  vector<int> di, dw;
    for(int i=0; i<h; i++)
      for(int j=0; j<w; j++){
        if(g[i][j]=='#'){
          di.push_back(i);
          break;
        }
      }
      for(int i=0; i<w; i++)
        for(int j=0; j<h; j++){
          if(g[j][i]=='#') {
            dw.push_back(i);
            break;
          }
        }
        for(int i=0; i<di.size(); i++){
          for(int j=0; j<dw.size(); j++){
            cout << g[di[i]][dw[j]];

          }
          cout << endl;
        }
}
