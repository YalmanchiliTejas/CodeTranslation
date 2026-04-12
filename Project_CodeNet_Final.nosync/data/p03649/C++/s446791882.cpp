#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
  int64 N;
  cin >> N;
  vector< int64 > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  auto check = [&](int64 v)
  {
    vector< int64 > B(A);
    for(int i = 0; i < N; i++) B[i] += v;
    int64 sub = 0;
    for(int i = 0; i < N; i++) {
      int64 beet = max(0LL, B[i] - (N - 1));
      if(beet == 0) continue;
      sub = min(v + 1, sub + (beet + N) / (N + 1));
    }
    return (sub <= v);
  };
  int64 low = 0, high = 1LL << 60;
  while(high - low > 0) {
    int64 mid = (low + high) / 2;
    if(check(mid)) high = mid;
    else low = mid + 1;
  }

  for(int64 i = max(0LL, low - 2000000); i <= low; i++) {
    if(check(i)) {
      cout << i << endl;
      return (0);
    }
  }
}
