#include <stdio.h>

int main()
{
   int r,g,b,a;
   scanf("%d", &r);
   scanf("%d", &g);
   scanf("%d", &b);
   a = r*100 + g*10 + b;
   
   if(a%4 == 0){
   printf("YES");
   }else{
   printf("NO");
   }
   
   return 0;
}