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
  
  //vector<int> a(n);  rep(i, 0, n) cin >> a.at(i);
  
  cout << (s.find("AC") == string::npos ?"No" :"Yes") << "\n";
  
  //cout << fixed << setprecision(10) << n << "\n";

}
