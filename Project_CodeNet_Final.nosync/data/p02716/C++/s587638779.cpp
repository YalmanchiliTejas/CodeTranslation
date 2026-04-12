#include <iostream>
#include <vector>
int main(){
  long N;
  std::cin >> N;
  std::vector<long> A(N+1, 0);
  for(long i = 1; i <= N; ++i){
    std::cin >> A[i];
  }
  std::vector<std::vector<long>> DP(N+1, std::vector<long>(3, 0));
  DP[1][2] = A[1];
  DP[2][2] = std::max(A[1], A[2]);
  if(N == 2){
    std::cout << DP[2][2] << std::endl;
    return 0;
  }
  DP[3][1] = std::max(DP[2][2], A[3]);
  DP[3][2] = A[1] + A[3];
  if(N == 3){
    std::cout << DP[3][1] << std::endl;
    return 0;
  }
  DP[4][1] = std::max(DP[3][1], A[4]);
  DP[4][2] = std::max(DP[3][2], DP[2][2] + A[4]);
  if(N == 4){
    std::cout << DP[4][2] << std::endl;
    return 0;
  }
  for(long i = 5; i <= N; ++i){
    if(i&1){
      DP[i][0] = std::max(DP[i-1][1], DP[i-2][0] + A[i]);
      DP[i][1] = std::max(DP[i-1][2], DP[i-2][1] + A[i]);
      DP[i][2] = DP[i-2][2] + A[i];
    }
    else{
      DP[i][0] = std::max(DP[i-1][0], DP[i-2][0] + A[i]);
      DP[i][1] = std::max(DP[i-1][1], DP[i-2][1] + A[i]);
      DP[i][2] = std::max(DP[i-1][2], DP[i-2][2] + A[i]);
    }
  }
  if(N&1){
    std::cout << DP[N][1] << std::endl;
  }
  else{
    std::cout << DP[N][2] << std::endl;
  }
  return 0;
}
