#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  int a,b,c;
  cin >> a >> b >> c;
  
  int sum = 100*a + 10*b + c;
  if(sum%4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;  
  
}
