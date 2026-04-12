#include <cstdio>
using namespace std;
int main(void){
  int r,g,b;
  scanf("%d%d%d",&r,&g,&b);
  puts((g*10+b)%4?"NO":"YES");
  return 0;
}