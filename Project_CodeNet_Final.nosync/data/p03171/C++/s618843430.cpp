#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <cstring>

int main(){
  
  // read problem
  long long int N, tmp;
  std::vector<long long int> a;
  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    scanf("%lld", &tmp);
    a.push_back(tmp);
  }
  
  // solve problem
  //dp_table[i][j] is the X-Y value if they start the game from the section from i-th element to j-th element
  std::vector<std::vector<long long int> > dp_table(N);
  for(long long int i = 0; i < N; i++){
    for(long long int j = 0; j < N; j++){
      dp_table[i].push_back(0);
    }
  }
  
  for(long long int i = 0; i < N; i++){
    dp_table[i][i] = a[i];
  }
  for(long long int l = 1; l < N; l++){
    for(long long int i = 0; i < N-l; i++){
      dp_table[i][i+l] = std::max(a[i] - dp_table[i+1][i+l], a[i+l] - dp_table[i][i+l-1]);
    }
  }
  
  /*for(long long int i = 0; i < N; i++){
    for(long long int j = 0; j < N; j++){
      std::cerr << dp_table[i][j] << " ";
    }std::cerr << std::endl;
  }*/
  
  std::cerr << "Answer:" << std::endl;
  std::cout << dp_table[0][N-1] << std::endl;
  
  return 0;
}
