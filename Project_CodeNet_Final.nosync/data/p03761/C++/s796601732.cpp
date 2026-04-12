#include <bits/stdc++.h>
#define rep(i,a,n) for (int i =a; i<n; i++)
using namespace std;

int main() {
  int n; cin >> n;
  string S[n]; int a[n][26]; rep(i,0,n) cin >> S[i];
  rep(i,0,n) rep(j,0,26) a[i][j] = 0;
  rep(i,0,n) {
    int size = S[i].size();
    rep(j,0,size) {
      int b = (int)S[i][j] - 'a';
      a[i][b]++;
    }
  }
  
  rep(i,0,26) {
    int ans =a[0][i];
    rep(j,0,n) {
      ans = min(ans,a[j][i]);
    }
    rep(k,0,ans) {
      if (ans != 0) {
        char c = (char)(i + 'a'); cout << c;
      }
    }
  }
  cout << endl; 
}