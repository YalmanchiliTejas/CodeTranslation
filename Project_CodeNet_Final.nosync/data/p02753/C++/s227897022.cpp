#include <bits/stdc++.h>
#define int long long
using namespace std;
using Graph = vector<vector<int>>;

signed main(){
 string A;
  cin >> A;
  
  if( A.at(0) == A.at(1)&& A.at(1) == A.at(2) ) cout << "No" << endl;
  else cout << "Yes" << endl;
  
}