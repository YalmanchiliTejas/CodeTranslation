#include <iostream>

int dice[3] = {1, 2, 3};


void cycle(int i, int j) {
  int temp;
  temp = dice[i];
  dice[i] = 7 - dice[j];
  dice[j] = temp;
}

void init() {
  for (int i = 0; i < 3; i ++)
    dice[i] = i + 1;
}


int main() {
  int n, i;
  int sum;
  std::string op;

  while (std::cin >> n) {
    if (n == 0) break;
    sum = 1;
    init();
    for (i = 0; i < n; i ++) {
      std::cin >> op;
      switch (op[0]) {
        case 'N':
          cycle(1, 0);
          break;
        case 'E':
          cycle(0, 2);
          break;
        case 'W':
          cycle(2, 0);
          break;
        case 'S':
          cycle(0, 1);
          break;
        case 'R':
          cycle(2, 1);
          break;
        case 'L':
          cycle(1, 2);
          break;
      }
      sum += dice[0];
    }
    std::cout << sum << std::endl;
  }
  
  return 0;
}