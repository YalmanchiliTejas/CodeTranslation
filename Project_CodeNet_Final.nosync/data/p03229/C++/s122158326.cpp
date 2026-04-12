#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG


signed main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  sort(all(A));
  
  vector<int> B(N), C(N);
  int a = 0, b = N-1, i = 0;
  while(true) {
    C[i] = A[a];
    a++;
    i++;
    if(i == N) break;
    C[i] = A[b];
    b--;
    i++;
    if(i == N) break;
  }
  a = 0, b = N-1, i = 0;
  while(true) {
    B[i] = A[b];
    b--;
    i++;
    if(i == N) break;
    B[i] = A[a];
    a++;
    i++;
    if(i == N) break;
  }
  
  int ans = 0;
  int m = 10000000000;
  rep(i, N-1) {
    ans += abs(C[i]-C[i+1]);
    m = min(m, abs(C[i]-C[i+1]));
  }
  ans += abs(C[0]-C[N-1]);
  m = min(m, abs(C[0]-C[N-1]));
  ans -= m;
  
  int aans = 0;
  m = 10000000000;
  rep(i, N-1) {
    aans += abs(B[i]-B[i+1]);
    m = min(m, abs(B[i]-B[i+1]));
  }
  aans += abs(B[0]-B[N-1]);
  m = min(m, abs(B[0]-B[N-1]));
  aans -= m;
  
  //rep(i, N) cout << C[i];
  //cout << endl;
  cout << max(ans, aans) << endl;

    
  
}