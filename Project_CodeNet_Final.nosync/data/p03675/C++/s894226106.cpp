#include <bits/stdc++.h>
using namespace std;

constexpr int si = 1001 * 1234;
int n, k, ar[si], a2[si];
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   while (cin >> n)
   {
      for (int i = 1; i <= n; i++) cin >> ar[i];
      int j = 1;
      if (n&1) {//odd
         for (int i = n; 1 <= i; i -= 2) a2[j++] = ar[i];
         for (int i = 2; i <= n; i += 2) a2[j++] = ar[i];
      }else {
         for (int i = n; 1 <= i; i -= 2) a2[j++] = ar[i];
         for (int i = 1; i <= n; i += 2) a2[j++] = ar[i];
      }

      for (int i = 1; i <= n; i++) cout << a2[i] << ' ';
      cout << '\n';
      //auto ans = sol();
      //cout << ans << "\n";
      //break;
   }
   return 0;
}