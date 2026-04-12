#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep2(i, a, b) for(int i = (a); i < (b); i++)
typedef long long ll;

int main() {
   int r, g, b;
   cin >> r >> g >> b;

   if ((r * 100 + g * 10 + b) % 4 == 0) {
       cout << "YES" << endl;
   } else {
       cout << "NO" << endl;
   }
}