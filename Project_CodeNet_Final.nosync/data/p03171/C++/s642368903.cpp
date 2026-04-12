#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<long long> A(N),psum(N+1);
  vector<vector<long long>> maxwin(N,vector<long long>(N));
  for(int i = 0; i < N; ++i){
    cin >> A[i];
    maxwin[i][i] = A[i];
    psum[i+1] = psum[i] + A[i];
  }
  for(int l = 1; l < N; ++l){
    for(int b = 0; b+l < N; ++b){
      int e = b+l;
      maxwin[b][e] = psum[e+1]-psum[b]-min(maxwin[b][e-1],maxwin[b+1][e]);
    }
  }
  cout << 2*maxwin[0][N-1]-psum[N];
  return 0;
}