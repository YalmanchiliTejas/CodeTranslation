#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
// using ll = long long;
// using P = pair<int,int>;

int main() {
	  long long N;
    cin >> N;
  
  	vector<long long> A(N);
  	for (long long i=0; i<N; ++i) {
      	cin >> A[i];
    }
    vector<long long> S(N+1, 0);
    for (long long i=0; i<N; ++i) {
        S[i+1] = S[i] + A[i];
    }

  	long long ans=0;
  	for (long long i=0; i<N; ++i) {
        long long llbuff = (S[N]-S[i+1])%(long long)1000000007;
        ans += (A[i]*llbuff)%(long long)1000000007;
    }
  	
  	cout << ans%(long long)1000000007 << endl;
    return 0;
}