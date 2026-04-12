#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long LL;

int main() {
  int N;
  cin >> N;
  vector<LL> A(N);
  REP(i, N) {
    cin >> A[i];
  }
  if(N % 2 == 0) {
    vector<LL> sum(N+2, 0LL);
    REP(i, N) {
      sum[i+2] = A[i] + sum[i];
    }
    LL ret = sum[N];
    for(int i=0; i<N; i+=2) {
      LL tret = sum[N+1] + sum[i] - sum[i+1];
      ret = max(ret, tret);
    }
    cout << ret << endl;
  } else {
    LL evensum = 0;
    for(int i =0; i<N; i+=2) {
      evensum += A[i];
    }
    int c_even = (N+1)/2;
    vector<LL> D(c_even);
    for(int i=0; i<c_even; ++i) {
      if(i == 0) {
        D[i] = A[0];
      } else {
        D[i] = D[i-1] + A[i*2] - A[i*2-1];
      }
    }
    vector<LL> minD(c_even), maxD(c_even);
    maxD[0] = 0;
    for(int i=1; i<c_even; ++i) {
      maxD[i] = max(D[i]-A[i*2], maxD[i-1]);
    }
    minD[c_even-1] = D[c_even-1];
    for(int i=c_even-2; i>=0; --i) {
      minD[i] = min(D[i], minD[i+1]);
    }
    LL tmin = numeric_limits<LL>::max();
    REP(i, c_even) {
      LL t = minD[i] - maxD[i];
      tmin = min(t, tmin);
    }
    cout << evensum - tmin << endl;
  }
}