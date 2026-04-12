#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a, b, c, x, y;
int main() {
   cin >> a >> b >> c >> x >> y;
   
   if (c*2>a+b) {
       cout << a*x+b*y;
   } else {
       if (x>=y) {
           cout << c*2*y+(x-y)*min(2*c,a);
       } else {
           cout << c*2*x+(y-x)*min(2*c,b);
       }
   }
   
}