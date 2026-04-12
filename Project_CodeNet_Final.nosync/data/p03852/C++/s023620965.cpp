#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
#define rep(i, j, n) for (int i = j; i < n; i++)
#define out(ans) cout << ans << endl;
const long long mod = 1e9 + 7;

int main(){

  char c;cin>>c;
  string s="aiueo";

  rep(i,0,s.size()){
    if(s[i]==c){out("vowel");return 0;}
  }
  out("consonant");


  return 0;
}
