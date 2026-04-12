#include <bits/stdc++.h>
using namespace std;

int main () {
  
  long long N;
  cin >> N;
  
  vector<long long> A(N);
  for (long long i = 0; i < N; i++) cin >> A[i];
  
  reverse(A.begin(), A.end());
  
  vector<long long> ans;
  ans.push_back(A[0]);
  
  for (long long i = 1; i < N; i++) {
    
    if (A[i] >= ans[ans.size() - 1]) ans.push_back(A[i]);
    
    else if (A[i] < ans[0]) ans[0] = A[i];
    
    else {
      long long a = 0;
      long long b = ans.size() - 1;
      
      while (b - a > 1) {
        long long mid = (a + b) / 2;
        if (A[i] >= ans[mid]) a = mid;
        else b = mid;
      }
      
      
      ans[b] = A[i];
    }
    
  }
  
  cout << ans.size() << endl;
    
  
}