#include <cstdio>
#include <cstring>
using namespace std;
char q[6];

int main() {
  scanf("%s", q);
  int len_ = strlen(q);
  for(int i = 0;i < len_; i++) {
    if(q[i] == 'A' && q[i + 1] == 'C') {printf("Yes\n");return 0;}
  }
  printf("No\n");
  return 0;
}
