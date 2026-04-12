#include <iostream>
#include <vector>

int main(){
  int N;
  std::cin>>N;
  std::vector<int> a;
  std::vector<int> h;
 
  int dummy;
  for(int i = 0; i < N;i++ ){
    std::cin>>dummy;
    h.push_back(dummy);
  }

  int Ryokan_Ocean=1;
  int k;
  int points;
  for(int i=1;i<N;i++){
    k = 0;
    points = 0;
    while(k<i){
      if(h[k]<=h[i]) points++;
      k++;
    }
    if(points == i) Ryokan_Ocean++;
  }

  std::cout<<Ryokan_Ocean<<std::endl;
  return 0;
}
