#include<bits/stdc++.h>
using namespace std;
int main()
{

   long long N, K;

   while(cin >> N >> K) {
      long long b, ans = 0;
      if(K == 0){
         cout << N * N << endl;
         continue;
      }
      for(b = K + 1; b <= N; b++) {
         long long x = (K == 0)? 1 : K;
         ans += (b - x) * (N / b);

         long long low = N / b * b;
         low = low + K;
         if(low <= N)
            ans += N - low + 1;
         //cout << ans << endl;
      }

      cout << (ans) << endl;
   }
   return 0;
}
