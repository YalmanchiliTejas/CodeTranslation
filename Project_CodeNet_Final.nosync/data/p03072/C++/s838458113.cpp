#include<bits/stdc++.h>

int main()
{
  
  int N,count=0;
  bool judge;
  
  scanf("%d",&N);
  
  int H[N];
  for(int i=0;i<N;i++){
    scanf("%d",&H[i]);
  }
  
  for(int i1=0;i1<N;i1++){
    judge=true;
    for(int i2=0;i2<i1;i2++){
      if(H[i1]<H[i2]){
        judge=false;
      }
    }
    if(judge==true){
      count++;
    }
  }
  
  printf("%d\n",count);
  
  return 0;
}