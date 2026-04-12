#include<bits/stdc++.h>
using namespace std;

int main () {
  int a,b,c;
  cin >> a >> b >> c;
  
  int A;
  A = 100*a + 10*b + c;
  
  if ( A % 4 == 0 ) {
    cout << "YES" << endl;
  }
  
    if (!( A % 4 == 0 )) {
    cout << "NO" << endl;
  }
}
