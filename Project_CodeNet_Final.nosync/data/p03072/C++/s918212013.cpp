#include<iostream>
int main(){
  short n,a[100], count=0;
  std::cin>>n;
  for(short i=0;i<n;i++){
    std::cin>>a[i];
  }
  short max = a[0];
  for(short i=0;i<n;i++){
    if(a[i]>=max){
      count++;
      max = a[i];
      //std::cout<<max<<" "<<a[i]<<std::endl;
    }
  }
  std::cout<<count;
  return 0;
}
