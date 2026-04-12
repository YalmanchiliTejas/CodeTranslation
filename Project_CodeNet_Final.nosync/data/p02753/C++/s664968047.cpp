#include <iostream>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  string ans = "No";

  if(s[0] == 'A'){
    if(s[1] == 'B' || s[2] == 'B'){
      ans = "Yes";
    }
  }

  if(s[0] == 'B'){
    if(s[1] == 'A' || s[2] == 'A'){
      ans = "Yes";
    }
  }


  cout << ans << endl;

  return 0;
}
