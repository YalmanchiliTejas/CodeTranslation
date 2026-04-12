#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;
using P = pair<int, int>; 
using ll = long long;

int main()
{
  int h, w;
  cin >> h >> w;
  char c[h][w];
  vector<int> a(h);
  vector<int> b(w);
  rep(i, h){
    rep(j, w) {
      cin >> c[i][j];
      if (c[i][j] == '#') {
        a[i] = 1;
        b[j] = 1;
      }
    }
  }
  
  rep(i, h){
    rep(j, w) {
      if(a[i] && b[j]) cout << c[i][j];
    }
    if(a[i])cout << endl;
  }                
  return 0;
}