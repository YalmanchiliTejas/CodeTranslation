#include<stdio.h>
int main()
{
 int score[11],win,lose,draw,point[11];
 int n,i,j,k;
 char str[11][21];
 
 for(k=0;;k++){
  scanf("%d",&n);
  if(n==0)break;
  if(k!=0)puts("");
  for(i=0;i<n;i++){
   scanf("%s",str[i]);
   scanf("%d%d%d", &win, &lose, &draw);
   score[i]=win*3+draw;
   point[i]=score[i];
  }
  for(i=0;i<n;i++){
   for(j=0;j<n;j++){
    if(point[i]>point[j]){
     point[10]=point[i];
     point[i]=point[j];
     point[j]=point[10];
    }
   }
  }
  for(i=0;i<n;i++){
   for(j=0;j<n;j++){
    if(point[i]==score[j]){
     printf("%s,%d\n",str[j],score[j]);
     score[j]=-1;
     break;
    }
   }
  }
 }
 return 0;
}