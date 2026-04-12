#include <bits/stdc++.h>
using namespace std;

int main() {
  string s,t;
  cin >> s >> t;
  vector<int> a,b;
  int k=0; 
  for(int i=0; i<s.size(); i++) {
    if(k<t.size()&&s[i]==t[k]) {
      a.push_back(i);
      k++;
    }
  }
  k=t.size()-1;
  for(int i=s.size()-1; i>=0; i--) {
    if(k>=0&&s[i]==t[k]) {
      b.push_back(i);
      k--;
    }
  }
  reverse(b.begin(),b.end());
  if(a.size()==t.size()&&a==b) cout << "yes" << endl;
  else cout << "no" << endl;
  return 0;
}
