#include<iostream>
using namespace std;

long long solve(string N, int K){
  long long ret = 0;
  if(K == 1){
    ret = 9 * (N.length() - 1) + (N[0] - '0');
  }else if(K == 2){
    if(N.length() < 2){
      ret = 0;
    }else{
      long long top_zero = 9 * 9 * (N.length() - 1) * (N.length() - 2) / 2;
      long long top_lt = (N[0] - '0' - 1) * 9 * (N.length() - 1);
      int first_nonzero_idx = 1;
      while(first_nonzero_idx < N.length() && N[first_nonzero_idx] == '0'){
        first_nonzero_idx++;
      }
      long long top_eq = 0;
      if(first_nonzero_idx < N.length()){
        top_eq = solve(N.substr(first_nonzero_idx, N.length() - first_nonzero_idx), K - 1);
      }
      ret = top_zero + top_lt + top_eq;
    }
  }else{
    if(N.length() < 3){
      ret = 0;
    }else{
      long long top_zero = 9LL * 9 * 9 * (N.length() - 1) * (N.length() - 2) * (N.length() - 3) / 6;
      long long top_lt = 9LL * 9 * (N[0] - '0' - 1) * (N.length() - 1) * (N.length() - 2) / 2;
      int first_nonzero_idx = 1;
      while(first_nonzero_idx < N.length() && N[first_nonzero_idx] == '0'){
        first_nonzero_idx++;
      }
      long long top_eq = 0;
      if(first_nonzero_idx < N.length()){
        top_eq = solve(N.substr(first_nonzero_idx, N.length() - first_nonzero_idx), K - 1);
      }
      ret = top_zero + top_lt + top_eq;
    }
  }
  return ret;
}

int main(){
  string N;
  cin >> N;

  int K;
  cin >> K;


  cout << solve(N, K) << endl;
}
