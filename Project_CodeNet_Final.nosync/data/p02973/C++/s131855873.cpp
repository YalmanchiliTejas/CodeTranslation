#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1000000001;

int main(){
   int N;
   std::cin >> N;
   int A[N];
   for(int i=0; i<N; ++i){
      std::cin >> A[i];
   }

   int dp[N+1];
   std::fill(dp, dp+N+1, INF);
   std::reverse(A, A+N);
   for(int i=0; i<N; ++i){
      *std::upper_bound(dp, dp+N, A[i]) = A[i];
   }
   std::cout << std::lower_bound(dp, dp+N, INF) - dp << std::endl;

   return 0;
}
