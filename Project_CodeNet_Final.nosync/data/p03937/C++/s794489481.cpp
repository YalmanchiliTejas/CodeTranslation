#include <bits/stdc++.h>

 using namespace std;
  char Arr[10][10];
  int main(){
   int H,W;
   scanf("%d%d",&H,&W);
   for(int i=0;i<H;i++){
    scanf("%s",Arr[i]);
   }
   int Count = 0;
  for(int i =0;i<H;i++){
    for(int j=0;j<W;j++){
        if(Arr[i][j]=='#')Count++;
    }
  }
  int m=0,n=0;
  int Found = 1;
  while(m<H&&n<W){
    if(m==H-1&&n==W-1)break;
    if(Arr[m][n+1]=='#'){
        n++;
        Found++;
    }
    else if(Arr[m+1][n]=='#'){
        m++;
        Found++;
    }else{
//    printf("%d %d %d %d",m,n,Found,Count);
     printf("Impossible");
     return 0;
    }
  }
//  printf("%d %d\n",Found,Count);
  if(Found==Count)printf("Possible");
  else printf("Impossible");
  }
