#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int h, w;
  cin >> h >> w;
  int a[h][w];
  for(int i=0; i<h; i++){
    for(int j=0; j<w; j++){
      char c;
      cin >> c;
      if(c=='.') a[i][j] = 0;
      else a[i][j] = 1;
    }
  }
  bool t[w],y[h];
  for(int i=0; i<h; i++){
    y[i] = false;
    int tmp = 0;
    for(int j=0; j<w; j++){
      tmp += a[i][j];
    }
    if(tmp == 0) y[i] = true;
  }
  for(int i=0; i<w; i++){
    t[i] = false;
    int tmp = 0;
    for(int j=0; j<h; j++){
      tmp += a[j][i];
    }
    if(tmp == 0) t[i] = true;
  }
  for(int i=0; i<h; i++){
    if(y[i]) continue;
    for(int j=0; j<w; j++){
      if(t[j]) continue;
      if(a[i][j]==1) cout << "#";
      else cout << ".";
    }
    cout << endl;
  }
  return 0;
}
