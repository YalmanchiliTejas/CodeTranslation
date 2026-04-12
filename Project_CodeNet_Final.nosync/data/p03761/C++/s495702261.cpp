#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
using namespace std;
int inf = 1e18;

int main() {

  int n; cin >> n;
  vector<string> a(n);
  vector<int> c(26, inf);
  for(int i=0; i<n; i++){
    cin >> a[i];
    vector<int> tmp(26, 0);
    for(int j=0; j<a[i].size(); j++){
      tmp[ a[i][j]-'a' ]++;
    }
    for(int j=0; j<26; j++){
      c[j] = min(c[j], tmp[j]);
    }
  }
  string ans = "";
  for(int i=0; i<26; i++){
    ans += string(c[i], 'a'+i);
  }
  cout << ans << endl;




  return 0;
}
