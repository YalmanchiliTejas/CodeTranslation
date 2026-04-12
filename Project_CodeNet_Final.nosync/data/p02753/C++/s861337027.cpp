#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  string s;
  cin >> s;
  string ans = "Yes";
  if(s.at(0) == s.at(1) && s.at(1) == s.at(2)) ans = "No";
  cout << ans << endl;
  
}