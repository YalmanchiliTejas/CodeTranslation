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
  long long tv = 0;
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
  while (1){
    vector<long long> b(N);
    for (int i = 0; i < N; i++){
      b[i] = a[i] + ans;
    }
    long long cnt = 0;
    for (int i = 0; i < N; i++){
      cnt += b[i] / (N + 1);
    }
    if (cnt < ans){
      break;
    }
    ans++;
  }
  cout << ans - 1 << endl;
}