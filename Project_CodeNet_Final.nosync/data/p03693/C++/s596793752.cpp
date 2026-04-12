#include <cstdio>

int main(int argc, char const *argv[]) {
  int r,g,b;
  int n;
  scanf("%d %d %d\n", &r,&g,&b);
  n=100*r+10*g+b;
  if(n%4==0){
    printf("YES\n");
  }
  else{
    printf("NO\n");
  }
  return 0;
}
