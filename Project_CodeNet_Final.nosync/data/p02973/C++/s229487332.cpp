#include <iostream>
#include <vector>
#include <map>
#include <set>

int main(void){

  int n;
  std::cin >> n;
  std::vector<int> A(n);
  std::vector<int> groupid(n, -1);
  std::vector<std::set<int> > groups;

  for(int i=0; i<n; i++){
    std::cin >> A[i];
  }

  std::set<std::pair<int, int> > tops;
  int count = 0;
  for(int i=0; i<n; i++){
    std::pair<int, int> now = std::make_pair(A[i], n-i);
    if(tops.size() == 0){
      tops.insert(now);
      count++;
      continue;
    }

    auto target = tops.lower_bound(now);
    if(target == tops.begin()){
      tops.insert(now);
      count++;
      continue;
    }
    auto before = target--;
    //std::cout << (*target).first << " " << (*target).second << std::endl;
    //std::cout << (*before).first << " " << (*before).second << std::endl;
    if(*(target) < now){
      tops.erase(*(target));
      tops.insert(now);
    }else{
      tops.insert(now);
      count++;
    }
  }

  std::cout << count << std::endl;

  return 0;
}