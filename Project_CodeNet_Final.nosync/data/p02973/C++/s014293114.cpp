#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  int N;
  std::cin >> N;

  std::vector<int> A_arr(N);
  for(int i = 0; i < N; i++){
    std::cin >> A_arr[i];
    A_arr[i] *= -1;
  }

  std::vector<int> current_arr;
  for(int i = 0; i < N; i++){
    auto change_it = std::upper_bound(current_arr.begin(), current_arr.end(), A_arr[i]);
    if(change_it == current_arr.end()){
      current_arr.push_back(A_arr[i]);
    }else{
      *change_it = A_arr[i];
    }
  }
  std::cout << current_arr.size() << std::endl;

  return 0;
}

