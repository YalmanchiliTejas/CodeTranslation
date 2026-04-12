#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000000000;
int main(){
  int N;
  cin >> N;
  vector<long long> a(N);
  for (int i = 0; i < N; i++){
    cin >> a[i];
  }
  long long tv = -100;
  long long fv = INF;
  while (fv - tv > 1){
    long long mid = (tv + fv) / 2;
    vector<long long> b(N);
    for (int i = 0; i < N; i++){
      b[i] = a[i] + mid;
    }
    long long cnt = 0;
    for (int i = 0; i < N; i++){
      cnt += b[i] / (N + 1) - 1;
    }
    if (cnt >= mid){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  long long ans = tv;
  long long curr = tv;
  while (1){
    vector<long long> b(N);
    for (int i = 0; i < N; i++){
      b[i] = a[i] + curr;
    }
    long long cnt = 0;
    for (int i = 0; i < N; i++){
      cnt += b[i] / (N + 1);
    }
    ans = curr - 1;
    if (cnt < curr && curr > 0 || curr == tv + 1000000){
      break;
    }
    curr++;
  }
  cout << ans << endl;
}