#include <bits/stdc++.h>
using namespace std;

int N, A[1 << 20], C[1 << 20];
long long ans = 0;

int main() {
	cin >> N;
    for(int i = 0;i < N;i++) {
      cin >> A[i];
    }

    for(int c = 1;c < N;c++) {
      
      int l = 0, r = N-1;
      long long tans = 0;
      while(l < N) {
        C[l]++;C[r]++;
        if(C[l] > 1 || C[r] > 1) {
           break;
        }
        tans += A[l] + A[r];
        if(N - 1 - l  > c) {
        	ans = max(ans, tans);
        }
        l += c;
        r -= c;
      }
     
      l= 0; r =N-1;
      while ( l<N) {
       C[l] =C[r] = 0;
       l += c;
       r -= c;
      }
    }
    cout << ans;
	return 0;
}