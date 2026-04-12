#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  string s;
  map<char,int> a, b;
  for(int i=0; i<n; i++) {
    cin >> s;
    if(i==0) for(int j=0; j<s.size(); j++) b[s[j]]++;
    else for(int j=0; j<s.size(); j++) a[s[j]]++;
    
    if(i==0) continue;
    else {
      for(auto p : b) {
        if(a.count(p.first)) b[p.first] = min(a[p.first], b[p.first]);
        else b[p.first] = 0;
      }
      for(auto p : a) a[p.first] = 0;
    }
  }
  
  string ans;
  for(auto p : b) {
    for(int i=0; i<b[p.first]; i++) {
      ans.push_back(p.first);
    }
  }
  
  cout << ans << endl;
  return 0;
}