#include<iostream>
#include<algorithm>
#include<vector>
typedef std::pair<char,int> info;

bool cmp(const info &p,const info &q){
  return p.second > q.second;
}

int main(){
  int a,s;
  std::vector<info> vec;
  while(true){
    std::cin >> a >> s;
    if(a+s == 0)break;
    vec.clear();
    vec.push_back(info('A',a+s));
    for(int i=1;i<=4;i++){
      std::cin >> a >> s;
      vec.push_back(info((char)('A'+i),a+s));
    }
    sort(vec.begin(),vec.end(),cmp);
    std::cout << vec[0].first << " " << vec[0].second << std::endl;
  }

  return 0;
}