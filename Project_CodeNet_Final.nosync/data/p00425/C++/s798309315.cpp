#include <iostream>

int main(){
  int n;
  while(std::cin >> n, n){
    int dice[6] = {1, 2, 3, 6, 5, 4};
    int result = 0;
    for(; n > 0; --n){
      std::string sosa;
      std::cin >> sosa;
      int tmp;
      switch(sosa.at(0)){
        case 'N':
          tmp = dice[0];
          dice[0] = dice[1];
          dice[1] = dice[3];
          dice[3] = dice[4];
          dice[4] = tmp;
          break;
        case 'E':
          tmp = dice[0];
          dice[0] = dice[5];
          dice[5] = dice[3];
          dice[3] = dice[2];
          dice[2] = tmp;
          break;
        case 'W':
          tmp = dice[0];
          dice[0] = dice[2];
          dice[2] = dice[3];
          dice[3] = dice[5];
          dice[5] = tmp;
          break;
        case 'S':
          tmp = dice[0];
          dice[0] = dice[4];
          dice[4] = dice[3];
          dice[3] = dice[1];
          dice[1] = tmp;
          break;
        case 'R':
          tmp = dice[1];
          dice[1] = dice[2];
          dice[2] = dice[4];
          dice[4] = dice[5];
          dice[5] = tmp;
          break;
        case 'L':
          tmp = dice[1];
          dice[1] = dice[5];
          dice[5] = dice[4];
          dice[4] = dice[2];
          dice[2] = tmp;
      }
      result += dice[0];
    }
    std::cout << result + 1 << std::endl;
  }
}