#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1000000000; 

int main(){
  string s;
  cin >> s;
  if(s[0] == s[1] && s[1] == s[2] && s[0] == 'A'){
    cout << "No" << endl;
    return 0;
  }
  else if(s[0] == s[1] && s[1] == s[2] && s[0] == 'B'){
    cout << "No" << endl;
    return 0;
  }
  else{
    cout << "Yes" << endl;
  }
}