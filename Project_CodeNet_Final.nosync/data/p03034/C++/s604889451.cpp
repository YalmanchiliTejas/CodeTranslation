#include <iostream>
#include <vector>
#include <cmath>

using lli=long long int;

int main(){
  int N;
  std::cin >> N;

  std::vector<lli> s_arr(N);
  for(int i = 0; i < N; i++){
    std::cin >> s_arr[i];
  }

  lli score_max = -1;
  for(int nforward = 1; nforward < N; nforward++){
    lli score = s_arr[N-1];
    lli score_n = score;
    int nstep = 0;
    while(true){
      nstep++;
      int a = N-1-nforward*nstep;
      if(a%nforward==0 && 2*a<=N-1) break;
      if(a<nforward) break;
      score += s_arr[nstep*nforward]+s_arr[a];
      score_n = std::max(score_n, score);
    }
    score_max = std::max(score_max, score_n);
  }

  std::cout << score_max << std::endl;

  return 0;
}

