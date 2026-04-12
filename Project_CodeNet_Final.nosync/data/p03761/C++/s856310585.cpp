#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  
  string s[n] = {""};
  rep(i,n) cin>>s[i];
  
  int az = 26;
  int azc[az] = {0};
  
  rep(i,az) {
    char alp = (char)('a'+i);
    int c;
    
    rep(i,n) {
      string S = s[i];
      
      int alpc = count(all(S), alp);
      if(i==0) {
        c = alpc;
      } else {
        c = min(c, alpc);
      }      
    }
    
    azc[i] = c;
  }
  
  rep(i,az) {
    
    int c = azc[i];
    rep(j,c) cout<<(char)('a'+i);
  }
  
  return 0;
}