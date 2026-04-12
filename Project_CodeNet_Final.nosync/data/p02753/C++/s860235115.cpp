#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) begin(v), end(v)
#define allg(v) begin(v), end(v), greater<int>()



int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  if(!(s.find("A") == string::npos) and !(s.find("B") == string::npos))
    cout << "Yes" << "\n";
  else
    cout << "No" << "\n";

}
