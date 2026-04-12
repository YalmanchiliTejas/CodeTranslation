#include <iostream>
int main(){
  int a,b,c;
  std::cin>>a>>b>>c;
  int d = a*100 + b*10 + c;
  if(d%4==0){
    printf("YES"); 
  }else{
    printf("NO");
  }
  return 0;
} 