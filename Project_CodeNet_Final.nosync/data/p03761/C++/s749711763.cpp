#include <iostream>
#include <algorithm>
#include <string>

int n;
int number[51]['z'-'a'+1];
int main(){
  std::cin>>n;
  std::string temp;
  for(int i=0;i<n;++i){
    std::cin>>temp;
    for(size_t j=0;j<temp.size();++j)
      ++number[i][temp[j]-'a'];
  }
  
  int temp2=1000;
  for(int i=0;i<'z'-'a'+1;++i){
    temp2=1000;
    for(int j=0;j<n;++j)
      temp2=std::min(temp2,number[j][i]);
    for(int j=0;j<temp2;++j)
      std::cout<<static_cast<char>(i+'a');
  }
  std::cout<<std::endl;
  return 0;
}