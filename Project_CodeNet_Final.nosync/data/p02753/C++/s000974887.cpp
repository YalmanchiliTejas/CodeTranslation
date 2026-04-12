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
  
  if(s.at(0) == s.at(1) && s.at(1) == s.at(2) )
    cout << "No";
  else 
    cout << "Yes";


}
