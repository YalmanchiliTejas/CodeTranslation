#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <array>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cstdint>
#include <unordered_set>
#include <ctime>
#include <numeric>
#include <cstdint>

using llint = long long int;

template<typename T>
void dump(const T& arr){
  std::cout << "[";
  for(const auto& elem: arr){
    std::cout << elem << ", ";
  }
  std::cout << "]" << std::endl;
}

llint sum(const std::vector<llint> &arr, int st, int ed){
  llint ret = 0;
  for(int i=st; i<ed; i++){
    ret += arr[i];
  }
  return ret;
}

void solve(void){
  llint N, X, M;
  std::cin >> N >> X >> M;
  
  std::map<llint, int> visited;
  std::vector<llint> history;
  llint result = 0;
  for(int i=0; i<N; i++){
    if(visited.find(X) != visited.end()){
      llint nokori = N - i;
      int len_loop = i - visited[X];
      llint n_loop = nokori / len_loop;
      llint loop_amari = nokori % len_loop;
      llint sum_loop = sum(history, visited[X], i);
      result += sum_loop * n_loop + sum(history, visited[X], visited[X]+loop_amari);
      break;
    }

    // else
    visited[X] = history.size();
    history.push_back(X);
    result += X;
    
    X = (X*X)%M;
  }
  
  std::cout << result << std::endl;
  return;

}
int main(void){
  solve();
  return 0;
}



