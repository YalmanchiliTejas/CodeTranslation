#include<stdio.h>
int main()
{
  int N;
  int H;
  int i;
  int counter=0;
  int hight=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
  {
    scanf("%d",&H);
    if(H>=hight)
    {
      counter++;
      hight=H;
    }
  }
  printf("%d",counter);
  return 0;
}