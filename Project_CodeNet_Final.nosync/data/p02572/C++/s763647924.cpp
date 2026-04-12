#include <bits/stdc++.h>
using namespace std;

int main(){//main_program
  int N;
  int64_t sum = 0;
  int64_t kei = 0;
  cin >> N;
  vector<int> A(N);
  vector<int64_t> B(N);
  
  for(int i = 0;i<N;i++){
    cin >> A.at(i);
    B.at(i) = A.at(i)%1000000007;
  }
  
  for(int i = N-1;i>0;i--){
    kei += B.at(i);
    kei %= 1000000007;
    sum += (B.at(i-1) * kei);
    sum %= 1000000007;
  }
  
  cout << sum <<endl;
  
}