#include <bits/stdc++.h>
using namespace std;
long long f(long long X, int N, vector<long long> &cnt1, vector<long long> &cnt2){
  if (N == 0){
    return 1;
  } else if (X == 1){
    return 0;
  } else if (X <= cnt1[N - 1] + 1){
    return f(X - 1, N - 1, cnt1, cnt2);
  } else if (X <= cnt1[N - 1] + 2){
    return cnt2[N - 1] + 1;
  } else if (X <= cnt1[N - 1] * 2 + 2){
    return cnt2[N - 1] + 1 + f(X - cnt1[N - 1] - 2, N - 1, cnt1, cnt2);
  } else {
    return cnt2[N];
  }
}
int main(){
  int N;
  long long X;
  cin >> N >> X;
  vector<long long> cnt(N + 1, 1);
  for (int i = 1; i <= N; i++){
    cnt[i] = cnt[i - 1] * 2 + 3;
  }
  vector<long long> cnt2(N + 1, 1);
  for (int i = 1; i <= N; i++){
    cnt2[i] = cnt2[i - 1] * 2 + 1;
  }
  cout << f(X, N, cnt, cnt2);
}