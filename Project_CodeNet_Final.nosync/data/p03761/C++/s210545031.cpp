#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for(ll i = 0; i < (n); ++i )
#define rep_rev(n,i) for(ll i = n; i >= 0; --i )
using namespace std;
const long long INF = 1LL << 60;

int n;
int main(){
  cin >> n;
  int alphabet[n][26];
  string s[n];
  rep(j,n){
    rep(i,26) alphabet[j][i] = 0;
  }
  //各文字列にどれだけの数のアルファベットが含まれているかチェック
  rep(j,n){
    cin >> s[j];
    rep(i,s[j].length()) alphabet[j][(s[j][i])-97]++;
  }

  vector<char> common;
  rep(i,26){
    int m = 10000;
    rep(j,n){
      if(m > alphabet[j][i]) m = alphabet[j][i];
    }
    char tmp = 'a' + i;
    rep(k,m) common.push_back(tmp);
  }
  if(common.size() == 0) cout << " " << endl;
  else{
    rep(i,common.size()) cout << common[i];
    cout << endl;
  }
  return 0;
}
