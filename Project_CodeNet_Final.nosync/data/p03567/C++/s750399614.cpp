#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define intll int long long
const int INF = 1e9;
const int MOD = 1e9 + 7;


int main() {
  string s ; 
  cin >> s ; 
  s = s+'@' ;
  
  rep(i,s.size()-1){
    string ans = "  " ;
    ans.at(0) = s.at(i)   ;
    ans.at(1) = s.at(i+1) ;
    if(ans == "AC" ) {
      cout << "Yes" <<endl ;
      return 0 ;
    }
  }
  
  cout << "No" <<endl ;
      
}
