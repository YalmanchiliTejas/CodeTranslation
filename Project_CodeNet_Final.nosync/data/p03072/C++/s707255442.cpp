#include <iostream>
#include <cstdlib>
#include <vector>

int main(int argc, char** argv) {
  int a;
  std::cin >> a;
  
  int vec[20];
  for (int i=0; i<a; i++) {
    std::cin >> vec[i];
  }

  bool can[100];
  can[0] = true;
  for (int i=1; i<a; i++) can[i] = false;
  
  for (int i=0; i<a; i++) {
    if (can[i]) {
      for (int j=i+1; j<a; j++) {
    	if (vec[i] <= vec[j]) {
           can[j] = true;
        } else {
          can[j] = false;
        }
      }
    }
  }
  
  int sum = 0;
  for (int i=0; i<a; i++) {
    if (can[i] == true) {
      sum++;
    }
  }
  std::cout << sum << std::endl;

  return 0;
}