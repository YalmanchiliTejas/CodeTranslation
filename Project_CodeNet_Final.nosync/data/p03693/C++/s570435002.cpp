#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

 int main() {
      int a,b,c;
      cin >> a >> b >> c;
      int s=100*a + 10*b +c;
      if (s % 4 ==0) cout << "YES" ;
         else cout << "NO";

      return 0;
}