#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  bool ans = false;
  for(int i=0;i<s.size()-1;i++) {
    if(s.substr(i, 2) == "AC")
      ans = true;
  }
  if(ans) 
    cout << "Yes"<< endl;
  else
    cout << "No" << endl;

}
