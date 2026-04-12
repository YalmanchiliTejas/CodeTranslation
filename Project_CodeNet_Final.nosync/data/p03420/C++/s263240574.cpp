#include <bits/stdc++.h>
#define int long long 
using namespace std;


signed main() {
  int N, K;
cin >> N >> K;

int ans = 0;
for( int b = 1; b <= N; b++ ){
ans += max(0LL, b-K) * (N/b);
ans += max(0LL, (N%b)-K+1);
}

if( K == 0 ) ans -= N;

cout << ans << endl;
}
  

  

  

  

