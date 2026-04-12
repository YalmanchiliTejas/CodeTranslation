#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int h, w;  cin >> h >>w;
  vector<string> g(h);

  for(int i=0; i<h; i++)  cin >> g.at(i);
  
  int li=0, lj=0; string ans="Possible";
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      if(g[i][j]=='.') continue;
      if(1<abs(li-i)+abs(lj-j)) ans = "Impossible";
      li = i, lj=j;
      //cout << li << ' ' << lj << ' ' << ans << endl;
    }
  }
  cout << ans << endl;
  
}
