#include <iostream>
#include <cmath>

using namespace std;

int main(){
   long long N, K;
   cin >> N >> K;

   if(K==0){
      cout << N*N << endl;
      return 0;
   }

   long long ans = 0;
   for(long long b=K+1; b<=N; ++b){
      long long x = b-K;
      long long y = (N-K)/b;
      ans += x*y;
      ans += min(x,N-y*b-K+1);
   }
   cout << ans << endl;
   return 0;
}
