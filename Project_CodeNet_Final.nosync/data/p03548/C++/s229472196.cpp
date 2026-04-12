#include <bits/stdc++.h>
using namespace std;
 int main() {
     int x , y , z;
     cin >> x >> y >> z;
     int ans = 0;
     ans = (x + z -2 * z) / (y + z);
     cout << ans << endl;
     return 0;
 }