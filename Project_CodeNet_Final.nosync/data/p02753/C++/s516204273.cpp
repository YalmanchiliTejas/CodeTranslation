#include<bits/stdc++.h>

using namespace std;

int main(){
  string S;
  cin >> S;
  string ret = (S[0] == S[1] && S[1] == S[2] && S[2] == S[0]) ? "No" : "Yes";
  cout << ret;
  return 0;
}