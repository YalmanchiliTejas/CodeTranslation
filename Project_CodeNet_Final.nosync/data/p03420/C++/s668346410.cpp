#include <bits/stdc++.h>
using namespace std;

int N, K;

// (N+x) / b > N/b
int posInc(int b) {
   int lo = 1, hi = b;
   while(lo < hi) {
      int m = (lo + hi) / 2;
      if((N+m)/b > N/b) hi = m;
      else lo = m+1;
   }
   return lo;
}

int calc(int b) {
   if(K >= b) return 0;
   int p = posInc(b);
   if(K == 0) {
      if(p == b) return (N / b) * b;
      else return (N / b) * p + (N/b + 1) * (b - 1 - p + 1);
   } else {
      if(p > b-K) return (N/b) * (b - K);
      else return (N/b) * (p - 1) + (N/b + 1) * (b - K - p + 1);
   }
}

int main() {
   cin >> N >> K;
   long long cc = 0;
   for(int b = 1; b <= N; b++) {
      cc += calc(b);
   }
   cout << cc << endl;
}
