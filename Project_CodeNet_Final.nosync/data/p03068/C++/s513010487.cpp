#include <iostream>
#include <string>

int main(){
  int N; int K;
  std::string str;
  std::cin>>N;
  std::cin>>str;
  std::cin>>K;
  char a = str[K-1];
  char ast = '*';
  std::string output("");
  //std::cout<<a<<std::endl;
  for(auto &&r : str){
    if(r==a){
      output += a;
    }else{
      output += ast;
    }
  }
  std::cout<<output<<std::endl;
  return 0;
}
