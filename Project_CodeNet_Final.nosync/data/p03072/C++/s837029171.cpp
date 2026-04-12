#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N,T,ans;
  cin >> N;
  vector<long long> A(N);
  for (int i=0;i<N;i++) {
	cin >> A[i];
  }
  T=1;
  ans=0;
  for (int i=0;i<N;i++) {
    if (A[i]>=T) {T=A[i];ans++;}
  }
  cout << ans << endl;
}