#include <iostream>

int main(){
  int N;
  while(std::cin>>N&&N>0){
    int sum=0,max=-1,min=1001;
    for(int i=0;i<N;++i){
      int s;
      std::cin>>s;
      sum += s;
      max = std::max(s,max);
      min = std::min(s,min);
    }
    std::cout<<(sum-max-min)/(N-2)<<std::endl;
  }
  return 0;
}