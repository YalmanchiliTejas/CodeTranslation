#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int cnta = 0, cntb = 0;
  rep(i, 3){
    if(s[i] == 'A'){
      cnta++;
    }else if(s[i] == 'B'){
      cntb++;
    }
  }
  if(cnta == 0 || cntb == 0){
    cout << "No" << endl;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}