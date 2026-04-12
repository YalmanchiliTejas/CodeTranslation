#include <bits/stdc++.h>
using namespace std;

void solve(long long N, vector<long long> a){
  long long ans = 0;
  while (true) {
    for ( long long i = 0; i < N; i++ ) {
      while (a[i] >= N) {
        ans += (a[i] / N);
        for ( long long j = 0; j < N; j++ ) {
          if (i == j) continue;
          a[j] += (a[i] / N);
        }
        a[i] = a[i] % N;
      }
    }
    bool flag = false;
    for ( long long i = 0; i < N; i++ ) {
      if (a[i] >= N) { flag = true; }
    }
    if (flag == false) break;
  }
  cout << ans << endl;
}

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	solve(N, a);
	return 0;
}

