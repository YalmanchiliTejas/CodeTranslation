#include<bits/stdc++.h>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  string ans = "No";
  for(int i = 0; i < s.length()-1; i++){
    if(s[i] == 'A' && s[i+1] == 'C') ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}