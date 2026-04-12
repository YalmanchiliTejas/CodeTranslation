#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;

int main(void){
  string s; cin >> s;
  if(s[0] == 'A' && s[1] == 'A' && s[2] == 'A') cout << "No" << endl;
  else if(s[0] == 'B' && s[1] == 'B' && s[2] == 'B') cout << "No" << endl;
  else cout << "Yes" << endl;
  
  return 0;
}
