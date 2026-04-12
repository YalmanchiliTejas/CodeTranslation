#include <bits/stdc++.h>
using namespace std;

#define INF 2e+9

int N;
vector<int> a;

int LIS() {
  vector<long> dp(N,INF);
  for(int i=0; i<N; i++){
    *lower_bound(dp.begin(), dp.end(), a[i]+1) = a[i];
  }
  return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main() {
  cin >> N;
  a.resize(N);
  for(int i=0; i<N; i++){
    cin >> a[N-1-i];
  }
  cout << LIS() << endl;
}