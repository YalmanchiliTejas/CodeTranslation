#include<iostream>
int main(){
 int r,g,b;
 std::cin>>r>>g>>b;
 r=g*10+b;
 if(r%4==0){
  std::cout<<"YES"<<std::endl;
 }
 else if(r%4!=0){
  std::cout<<"NO"<<std::endl;
 }
 return 0;
}