#include<bits/stdc++.h>
using namespace std;
  int main(){
      int H,W;
      char ch;
      int a[200][200],sumH[200],sumW;
      scanf("%d%d",&H,&W);
      for(int i=0;i<H;i++)
        for(int j=0;j<W;j++){
            scanf("%c",&ch);
            while((ch!='.')&&(ch!='#'))scanf("%c",&ch);
            if(ch=='.')a[i][j]=0;
            else a[i][j]=1;            
        }
      for(int i=0;i<H;i++){
          sumH[i]=0;
          for(int j=0;j<W;j++)sumH[i]+=a[i][j];
      }
      for(int j=0;j<W;j++){
          sumW=0;
          for(int i=0;i<H;i++)sumW+=a[i][j];
          if(sumW==0){
              for(int i=0;i<H;i++)a[i][j]=-1;
          }
      }
      for(int i=0;i<H;i++){
          if(sumH[i]>0){
              for(int j=0;j<W;j++){
                  if(a[i][j]==0)printf(".");
                  else if(a[i][j]==1)printf("#");
              }
              printf("\n");
          }
      }
      
      return 0;
  }