#include <stdio.h>

int main()
{
 char A, B, C;
 scanf("%c%c%c", &A, &B, &C);
 if(A, B != C){
  printf("Yes\n");
 }else if(A, C != B){
  printf("Yes\n");
 }else if(B, C != A){
  printf("Yes\n");
 }else if( A==B, B==C){
  printf("No\n");
 }
 return 0;
}