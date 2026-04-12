#include<stdio.h>
int main(void)
{
  int n;
  int i;
  for(;;){
    scanf("%d",&n);
    if(n == 0) break;
    int s[n];
    for(i=0;i<n;i++){
      scanf("%d",&s[i]);
    }
    int max;
    max =s[0];
    for(i=1;i<n;i++){
      if(max<=s[i]){max=s[i];}
    }
    int min;
    min =s[0];
    for(i=1;i<n;i++){
      if(min>=s[i]){min=s[i];}
    }
    ;
    int score=0;
    for(i=0;i<n;i++){
      score=score + s[i];
    }
    score= score - min - max;
    score= score / (n-2);
    printf("%d\n",score);
  }
   
  return 0;
}