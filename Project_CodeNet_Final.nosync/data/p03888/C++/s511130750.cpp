#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main(){
  double a, b;
  cin >> a >> b;
  
  double ans = (a * b) / (a + b);

  cout << setprecision(15) << ans << endl;
}