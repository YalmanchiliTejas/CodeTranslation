#include <bits/stdc++.h>
using namespace std;
 int main() {
     int x, y, z, i, tmp, ans;
     cin >> x >> y >> z;
     for (i=1; i <= 1000000; i++) {
         tmp=(z*(i+1))+(y*i);
         if (tmp<=x) {
             continue;
         } else {
             break;
         }
     }
     
     cout << i-1 << endl;
     return 0;
 }