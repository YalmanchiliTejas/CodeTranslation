#include<iostream>
#include<string>

int main(){
  std::string str;
  std::cin>>str;
  if(str[0]==str[1] && str[1] == str[2])
    std::cout<<"No\n";
  else
    std::cout<<"Yes\n";
}
