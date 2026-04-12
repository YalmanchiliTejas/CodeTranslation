#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

typedef std::vector<int> vi;

bool isGone(int a, std::vector<int> gone){
  auto itr = std::find(gone.begin(), gone.end(), a);
  if(itr != gone.end()) return true;
  else return false;
}

int count(int depth, int pos, vi gone, std::map<int, vi> neighborNode){
  int root = 0;
  if(gone.size() == depth){
    for(auto x : neighborNode[pos]){
      if(isGone(x, gone)) continue;
      else return 1;
    }//auto x
    return 0;
  }else{
    for(auto x : neighborNode[pos]){
      int temp = pos;
      if(isGone(x, gone)) continue;
      else{
        pos = x;
        gone.push_back(x);
        root += count(depth, pos, gone, neighborNode);
        gone.pop_back();
        pos = temp;
      }
    }
  }//depth
  return root;
}

int main(){
  int N, M;
  std::cin >> N >> M;
  std::map<int, vi> neighborNode;
  for(int i = 0; i < M; i++){
    int tempA, tempB;
    std::cin >> tempA >> tempB;
    neighborNode[tempA].push_back(tempB);
    neighborNode[tempB].push_back(tempA);
  }
  vi gone;
  int pos = 1;
  gone.push_back(1);
  int pattern = count(N - 1, 1, gone, neighborNode);
  std::cout << pattern << std::endl;
}