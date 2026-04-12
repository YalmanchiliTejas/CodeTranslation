#include<bits/stdc++.h>
#define ll long long
#define INF 1000000ll
using namespace std;
signed main(){
  ll h,w;
  cin >> h >> w;
  vector<string> a(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }

  vector<bool> row(h, false);
  vector<bool> col(w, false);
  for (int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(a[i][j] == '#') {
        row[i] = true;
        col[j] = true;
      }
    }
  }
  
  for(int i = 0; i < h; i++) {
    if (row[i]) {
      for (int j = 0; j < w; j++) {
        if(col[j]) {
          cout << a[i][j];
        }
      }
      cout << "\n";
    }
  }
}