#include <iostream>
#include <vector>
#include <algorithm>

long all[51], allpat[51];

long dp(long i, long j){
  if(j == 0){
    return 0;
  }
  if(j == 1){
    if(i == 0) return 1;
    else return 0;
  }
  else if(j == all[i]){
    return allpat[i];
  }
  else{
    if(j <= all[i - 1] + 1){
      return dp(i - 1, j - 1);
    }
    else{
      return allpat[i] - dp(i - 1, all[i] - j - 1);
    }
  }
}

int main(){
  int n;
  long x;
  std::cin >> n >> x;
  all[0] = 1;
  allpat[0] = 1;
  for(int i = 0; i < n; i++){
    all[i + 1] = all[i] * 2 + 3;
    allpat[i + 1] = allpat[i] * 2 + 1;
  }
  std::cout << dp(n, x) << std::endl;
}