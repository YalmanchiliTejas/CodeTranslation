#include<iostream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

ll B[51], P[51], len[51];

ll calc(ll n, int l) {
   if (n == 0) {
      if (l != 0) return 0;
      else return 1;
   }
   if (1 <= n && n <= (len[l] - 3) / 2) return calc(n - 1, l - 1);
   if (n == (len[l] - 3) / 2 + 1) return calc(len[l - 1], l - 1) + 1;
   if ((len[l] - 3) / 2 + 1 < n && n < len[l] - 1) return calc(n - ((len[l] - 3) / 2 + 2), l - 1) + calc(len[l - 1], l - 1) + 1;
   else return calc(len[l - 1], l - 1) * 2 + 1;
}

int main() {
   int N;
   ll X;
   cin >> N >> X;

   B[0] = 0;
   P[0] = 1;
   len[0] = 1;

   for (int i = 1; i <= N; i++) {
      B[i] = B[i - 1] * 2 + 2;
      P[i] = P[i - 1] * 2 + 1;
      len[i] = B[i] + P[i];
   }

   cout << calc(X - 1, N) << endl;
   return 0;
}
