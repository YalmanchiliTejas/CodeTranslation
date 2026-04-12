#include <cstdio>

int main()
{
  int num, now, i, top = 0, res = 0;
  scanf("%d", &num);
  for(i = 0; i < num; i++){
    scanf("%d", &now);
    if(now >= top){
      res++;
      top = now;
    }
  }
  printf("%d\n", res);
  return  0;
}