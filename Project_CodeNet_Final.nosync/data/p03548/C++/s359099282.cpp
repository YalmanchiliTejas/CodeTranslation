#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ll long long

int main() {
   int x, y, z; // 椅子幅、人幅、隙間幅
   cin >> x >> y >> z;
   x -= z;
   int unit = y + z;
   int a = x / unit;
   cout << a << endl;

   return 0;
}