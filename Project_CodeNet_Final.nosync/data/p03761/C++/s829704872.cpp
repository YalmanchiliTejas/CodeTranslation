#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int n;
map<int,int> m[55];
string ans = "";
int main() {
  int n;
  cin >> n;
  rep(i,n){
    string s;
    cin >> s;
    rep(j,s.size()) m[i][s[j]-'a']++;
  };
  map<int,int> x;
  rep(c,26){
    int v = 1e9;
    rep(i,n) v = min(v,m[i][c]);
    x[c] = v;
  }
  string ans = "";
  rep(c,26)rep(i,x[c]) ans += (c+'a');
  cout << ans << endl;
}
