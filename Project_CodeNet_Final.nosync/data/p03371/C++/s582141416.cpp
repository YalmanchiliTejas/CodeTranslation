#include <bits/stdc++.h>

 using namespace std;
 typedef long long ll;
 #define rep(i, n) for(int i = 0; i < (int)(n); i++)

 int main() {
   int A, B, C, X, Y, ans;
   cin >> A >> B >> C >> X >> Y;

   if (A + B <= 2 * C) ans = A * X + B * Y;
   else if (X <= Y) {
     if (2 * C <= B) ans = Y * 2 * C;
     else ans = X * 2 * C + (Y - X) * B;
   }
   else if (2 * C <= A) ans = Y * 2 * C;
   else ans = Y * 2 * C + (X - Y) * A;

   cout << ans << endl;
 }
