#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long N, K;
 
int main() {
  cin >> N >> K;
  
    long long res = 0;
    for (long long b = K+1; b <= N; ++b) {
        long long tmp = min(b-1, b-K);
        long long A = N - (b-1);
        long long B = N-K;
        long long add = (A/b) * (b - K);
        if (B/b == A/b + 1) add += (B%b) + 1;
      
        tmp += add;
        res += tmp;
    }
  
  cout << res << endl;
    
}
 

   