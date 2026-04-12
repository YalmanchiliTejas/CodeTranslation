#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(){
  ll mod = 1000000007LL;
  int N;
  cin >> N;
  vector<int> A(N);
  ll sum = 0;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    sum += A[i];
  }
  ll ans = 0;
  sum -= A[0];
  for (int i=0; i<N-1; i++) {
    ans = (ans + ((A[i]) * (sum%mod))%mod)%mod;
    sum -= A[i+1];
  }
  cout << ans << endl;
}
