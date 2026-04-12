#include<bits/stdc++.h>
using namespace std;
int main(){
  string A;
  cin >> A;
  string ans = "Yes";
  if(A.at(0) == A.at(1) && A.at(1) == A.at(2)){
    ans = "No";
  }
  cout << ans << endl;
  return 0;
}