#include<iostream>
using namespace std;
 
int main(void) {
  int a, b, c;
  cin >> a >> b >> c;
  int ans=0;
  
  ans = 100*a+10*b+c;
  if (ans % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}