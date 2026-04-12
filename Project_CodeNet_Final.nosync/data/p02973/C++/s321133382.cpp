#include<iostream>
#include<vector>
#include<set>
signed main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(auto& ai:a)std::cin>>ai;
  std::multiset<int> s;
  for(auto ai:a){
    auto itr = s.lower_bound(ai);
    if(itr==std::begin(s)){
      s.emplace(ai);
      continue;
    }
    --itr;
    s.erase(itr);
    s.emplace(ai);
  }
  std::cout<< std::size(s) <<std::endl;
}