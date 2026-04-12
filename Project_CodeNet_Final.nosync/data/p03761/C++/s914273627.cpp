#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;cin>>n;
  int an[26][n];rep(i,26)rep(j,n)an[i][j]=0;
  rep(i,n) {
    string s;cin>>s;
    rep(j,s.size()) {
      int c = s[j] - 'a';
      an[c][i] ++ ;
    }
  }
  rep(i,26) {
    int m = *min_element(an[i], an[i]+n);
    char cc = 'a' + i;
    cout << string(m, cc);
  }
}
