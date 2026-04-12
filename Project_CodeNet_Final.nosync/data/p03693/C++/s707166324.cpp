#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s(3,'0'),ans;
  cin >> s.at(0) >> s.at(1) >> s.at(2);
  int num = stoi(s);
  if(num % 4 == 0){
    ans = "YES";
  }else{
    ans = "NO";
  }
  cout << ans << endl;
}