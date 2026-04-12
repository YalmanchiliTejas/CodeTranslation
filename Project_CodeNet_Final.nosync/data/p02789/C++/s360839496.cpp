#include <iostream>
using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  
  if (n > m)
    printf("No\n");
  else
    printf("Yes\n");

  return 0;
}