#include <stdio.h>
int main(){
  int i,m[17][17]={},j,cou,a;
  while(1){
    scanf("%d",&a);
    if(a==0)break;
    for(i=0;i<17;i++){
      for(j=0;j<17;j++){
      m[i][j]=0;
      }
    }
    cou=1;
    i=a/2+2;
    j=a/2+1;
    while(1){     
      m[i][j]=cou;
      cou++;
      if(cou>a*a)break;
      i++;
      j++;
      while(1){
	if(i==0)i=a;
	else if(i>a)i=1;
	if(j==0)j=a;	
	else if(j>a)j=1;
	if(m[i][j]!=0){
	  i++;
	  j--;
	}
	if(1<=i && i<=a && 1<=j && j<=a && m[i][j]==0)break;
      }
    }
    for(i=1;i<=a;i++){
      for(j=1;j<=a;j++){
	printf("%4d",m[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}