#include<stdio.h>
int main()
{
  int N;
  int H;
  scanf("%d",&N);
  int i;
  int hight=0;
  int counter=0;
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
