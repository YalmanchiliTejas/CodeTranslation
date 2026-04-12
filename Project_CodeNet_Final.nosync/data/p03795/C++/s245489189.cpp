#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if (n < 15) {
    printf("%d", (n * 800));
  } else
  {
    int cost = (n * 800);
    int reward = (n / 15) * 200;
    printf("%d", (cost - reward));
  }
}