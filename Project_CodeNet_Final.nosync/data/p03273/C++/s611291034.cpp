#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

int main() {
  int h,w; cin >> h >> w;
  vector<string> ws(h); 

  rep(i, h) {
    cin >> ws[i];
  }

  int count;
  vector<int> col(w);
  rep(i,w){
    int sum = 0;
    rep(j, h){
      if (ws[j][i] == '.')
        sum++;
    }
    if (sum == h)
      col[i] = 1;
    else 
      col[i] = 0;
  }

  rep(i, h){
    if(ws[i] != string(w, '.')) {
      rep(j, w) {
        if (col[j] == 0)
          cout << ws[i][j];
      }
      cout << endl;
    }
  }
}