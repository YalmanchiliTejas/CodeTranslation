#include "bits/stdc++.h"

#define REP(i, a, b) for (int i = (a); i <= (b); ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define FORV(a, A) for (auto &a : A)

using namespace std;

using ll = long long;

void Main()
{
   int N;
   cin >> N;
   ll S[N];
   FORV(s, S)
   {
      cin >> s;
   }

   ll ans = 0;
   ll score;
   REP(C, 1, N - 1)
   {
      score = 0;
      if ((N - 1) % C != 0)
      {
         for (int k = 1; C * (k + 1) < N; k++)
         {
            score += S[k * C];
            score += S[N - 1 - k * C];
            ans = max(ans, score);
         }
      }
      else if (N - 1 & 1)
      {
         for (int k = 1; C * k <= (N - 1) / 2; k++)
         {
            score += S[k * C];
            score += S[N - 1 - k * C];
            ans = max(ans, score);
         }
      }
      else
      {
         for (int k = 1; C * k < (N - 1) / 2; k++)
         {
            score += S[k * C];
            score += S[N - 1 - k * C];
            ans = max(ans, score);
         }
      }
   }
   cout << ans << endl;
}

int main()
{
   std::cin.tie(nullptr);
   std::ios_base::sync_with_stdio(false);
   std::cout << std::fixed << std::setprecision(15);
   Main();
   return 0;
}
