#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
  cin >> s;
  if((s[0]==s[1])&&(s[1]==s[2])){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  return 0;
}
