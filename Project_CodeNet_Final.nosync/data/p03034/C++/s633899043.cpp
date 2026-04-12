#include <vector>
#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> S(N);
  for(int i = 0; i < N; ++i) cin >> S[i];
  long long ans = 0;
  for(int i = 1; i < N; ++i){
    vector<long long> A(1,0), B(1,0);
    int r = (N-1)%i;
    for(int j = 0; j <= (N-1)/i; ++j){
      A.push_back(S[j*i]);
      B.push_back(S[j*i+r]);
    }
    for(size_t i = 1; i < A.size(); ++i) A[i] += A[i-1], B[i] += B[i-1];
    int M = A.size();
    for(int j = 0; j < M; ++j){
      long long a = i*j+r, b = a - i;
      if(a <= b) continue;
      if(b <= 0) continue;
      if(r == 0 and (a/i-1)*i+a < N-1) continue;
      long long s = A[M-j-1] + B.back() - B[j];
      ans = max(ans,s);
    }
  }
  cout << ans << endl;
}
