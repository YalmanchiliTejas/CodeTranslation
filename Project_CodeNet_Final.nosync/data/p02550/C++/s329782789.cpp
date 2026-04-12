#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
#include <climits>


int main(){
  long N,X,M;
  std::cin >> N >> X >> M;
  long table[100000]={};
  std::vector<long> P;
  long now=X;
  while(table[now]==0){
    P.push_back(now);
    table[now]=1;
    now=(now*now)%M;
  }
  long end=P.size();
  long tip=now;
  long start;

  for(long i=0; i<P.size(); i++){
    if(P[i]==tip){
      start=i;
      break;
    }
  }
  long loop=0;
  for(long i=start; i<end;i++){
    loop+=P[i];
  }
  
  long loop_num = (N-(start))/(end-start);

  long result=0;
  for(long i=0; i<start; i++){
    result+=P[i];
  }
  result+=loop_num*loop;
  for(long i=start; i<start+(N-start)%(end-start);i++){
    result+=P[i];
  }
  std::cout << result << std::endl;
  return 0;
}