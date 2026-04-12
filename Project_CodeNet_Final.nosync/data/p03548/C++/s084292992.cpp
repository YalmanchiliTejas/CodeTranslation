#include <iostream>
using namespace std;
int main(){
  int x, a, b;
  cin >> x >> a >> b;
  int ans;
  ans = (x-b)/(a+b);
  cout << ans << endl;
  return 0;
}