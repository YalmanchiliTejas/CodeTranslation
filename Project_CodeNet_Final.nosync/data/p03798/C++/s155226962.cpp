#include <iostream>
#include <string>
#include <vector>
#include <tuple>

auto app(int a1, int a2, std::string& S){
  std::vector<int> a_arr(S.size()+2);
  a_arr[0] = a1;
  a_arr[1] = a2;
  for(int i = 1; i < S.size()+1; i++){
    char s = S[i%(S.size())];
    if((s == 'o' && a_arr[i] == 0) || (s == 'x' && a_arr[i] == 1)) a_arr[i+1] = a_arr[i-1];
    else a_arr[i+1] = 1-a_arr[i-1];
  }
  if(a_arr[S.size()] == a_arr[0] && a_arr[S.size()+1] == a_arr[1]) return std::make_tuple(true, a_arr);
  return std::make_tuple(false, a_arr);
}

int main(){
  int N;
  std::cin >> N;

  std::string S;
  std::cin >> S;

  std::vector<int> ans_arr, tmp;
  bool b = false;
  int init_arr[4][2] = {{0,0},{0,1},{1,0},{1,1}};
  for(int i = 0; i < 4; i++){
    std::tie(b,ans_arr) = app(init_arr[i][0], init_arr[i][1], S);
    if(b) break;
  }

  if(b == false) std::cout << -1 << std::endl;
  else{
    for(int i = 0; i < N; i++){
      std::cout << (ans_arr[i] == 0 ? "S":"W");
    }
    std::cout << std::endl;
  }

  return 0;
}

