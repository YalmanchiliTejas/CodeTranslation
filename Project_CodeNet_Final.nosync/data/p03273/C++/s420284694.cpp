#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h){
    string str;
    cin >> str;
    a[i] = str;
  }
  
  vector<bool> row(h, false);
  vector<bool> col(w, false);
  rep(i, h){
    rep(j, w){
      if (a[i][j] == '#') row[i] = true, col[j] = true;
    }
  }
  
  rep(i, h){
    rep(j, w){
      if (row[i] && col[j]) cout << a[i][j];
    }
    if (row[i]) cout << endl;
  }
      
}
