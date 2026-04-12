#include <iostream>
#include <algorithm>
#include <vector>

const int INPUT_SIZE = 12;

int main(void){

  std::vector<int> stickVec(INPUT_SIZE);
  for(int i = 0; i < INPUT_SIZE; i++){
    std::cin >> stickVec[i];
  }

  std::sort(stickVec.begin(), stickVec.end());

  int cnt = 0;
  bool flag = true;
  for(int i = 0; i < INPUT_SIZE - 1; i++){

    if(cnt == 3){
      cnt = 0;
    }
    else if(stickVec[i] == stickVec[i+1]){
      cnt++;
    }
    else{
      flag = false;
      break;
    }
  }

  if(flag){
    std::cout << "yes" << std::endl;
  }
  else{
    std::cout << "no" << std::endl;
  }
  
  return 0;
}