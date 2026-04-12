#include<iostream>
int main(){
  int numOfHotel;
  int maxHeight{};
  int objHeight;
  int can_see{};
  std::cin>>numOfHotel;
  for (int idx{};idx<numOfHotel;++idx){
    std::cin>>objHeight;
    if (maxHeight<=objHeight){
      ++can_see;
      maxHeight=objHeight;
    }
  }
  std::cout<<can_see;
  return 0;
}
