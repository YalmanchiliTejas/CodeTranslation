#include <bits/stdc++.h>
#define rep(i,m,n) for(int i=m; i<n; i++)
#define co(n) cout << n << endl
using namespace std;

int main() {
  int h, w, n, m, c=0, d=0, e=0;
  cin >> h >> w;
  int a[w], b[h];
  char s[h][w]={}, ss[h][w]={}, sss[h][w]={};
  rep(i,0,h){
    rep(j,0,w){
      cin >> s[i][j];
    }
  }
  
  rep(i,0,h){
    c=0;
    rep(j,0,w) if(s[i][j]=='.') c++;
    a[i]=c;
  }
  rep(i,0,w){
    c=0;
    rep(j,0,h) if(s[j][i]=='.') c++;
    b[i]=c;
  }
  rep(i,0,h){
    rep(j,0,w){
      if(a[i]!=w && b[j]!=h) cout << s[i][j];
    }
    if(a[i]!=w) cout << endl;
  }
  
  return 0;
}
