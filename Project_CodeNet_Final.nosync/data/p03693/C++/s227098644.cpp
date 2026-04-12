#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n); ++i)


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int num = a*100 + b*10 + c;
  string ans = "NO";
  if(num%4 == 0) ans = "YES";
  cout << ans << endl;
  return 0;
  
}