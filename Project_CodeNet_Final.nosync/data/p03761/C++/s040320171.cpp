#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <string>

int main(){
  constexpr int a = 26;
  int n;
  std::cin>>n;
  std::vector<std::string> strs(n);
  for(auto &&s:strs)
    std::cin>>s;

  std::vector<std::array<int,a>> alphapat(n);
  for(int i=0;i<n;++i){
    for(const auto &c:strs[i]){
      alphapat[i][c-'a']++;
    }
  }

  std::array<int,a> common;
  for(int i=0;i<a;++i){
    common[i] = 51;
    for(int j=0;j<n;++j){
      if(alphapat[j][i]<common[i]) common[i] = alphapat[j][i];
    }
  }
  
  for(int i=0;i<a;++i){
    if(common[i]!=0){
      std::string str(common[i],'a'+i);
      std::cout<<str;
    }
  }
  std::cout<<std::endl;
  return 0;
}