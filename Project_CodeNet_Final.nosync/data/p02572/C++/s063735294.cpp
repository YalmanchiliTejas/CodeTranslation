#include <bits/stdc++.h>

using namespace std;
using llint = long long int;

#define mod (1000000000 + 7)

int main() {
  __int128 ans = 0;
  int N;
  cin >> N;
  llint A[N];
  for(llint &a : A)
    cin >> a;
  
  llint sum = 0;
  for(int i = 0; i < N; i++)
    sum += A[i];
  
  for(int i = 0; i < N - 1; i++) {
    sum -= A[i];
    ans += ((__int128)A[i]) * sum;
  }
  
  cout << (unsigned int)(ans % mod) << endl; 
}