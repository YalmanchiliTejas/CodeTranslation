#include<iostream>
#include<string>
int main(){
  size_t len,idx;
  std::string input;
  std::cin>>len>>input>>idx;
  char pin{input[idx-1]};
  for (auto& ch:input){
    if (ch!=pin)
      ch='*';
  }
  std::cout<<input;
  return 0;
}
