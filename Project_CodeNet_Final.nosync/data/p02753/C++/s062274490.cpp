#include <cstdio>
using namespace std;

int main() {
  char str[4];
  scanf("%s", &str);
  (str[0]==str[1] && str[1]==str[2]) ? printf("No") : printf("Yes");
  return 0;
}