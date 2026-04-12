#include<iostream>

int main() {
  int N;
  int H[20];
  int i, j;

  std::cin >> N;

  for(i=0; i<N; i++) {
    std::cin >> H[i];
  }

  int sum=0;
  for(i=0; i<N; i++) {
    for(j=0; j<i; j++) {
      if(H[j] > H[i]) break;
    }
    if(j==i) sum++;
  }

  std::cout << sum;

  return 0;
}
