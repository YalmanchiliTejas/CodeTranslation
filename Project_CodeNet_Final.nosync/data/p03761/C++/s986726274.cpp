#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int n, num[30][100];

int main(){
  cin >> n;
  rep(i, n){
    string s; cin >> s;
    rep(j, s.size()){
      num[s.at(j) - 'a'][i]++;
    }
  }
  string res = "";
  rep(i, 26){
    int m = 100000;
    rep(j, n) m = min(num[i][j], m);
    rep(j, m) res.push_back('a' + i);
  }
  cout << res << endl;
  return 0;
}
