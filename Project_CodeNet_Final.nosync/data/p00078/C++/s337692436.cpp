#include <stdio.h>

void fill_square(int num,int square[15][15],int is_filled[15][15],int x,int y,int n) {

  int flag=1;
  int i,j;

  if(y>=n) fill_square(num,square,is_filled,x,0,n);

  else if(y<0) fill_square(num,square,is_filled,x,n-1,n);

  else if(x>=n) fill_square(num,square,is_filled,0,y,n);

  else if(is_filled[x][y]==1) fill_square(num,square,is_filled,x+1,y-1,n);

  else {
    
    square[x][y]=num;

    is_filled[x][y]=1;

    for(i=0;i<n;i++) {

      for(j=0;j<n;j++) {

	if(is_filled[i][j]==0) flag=0;

      }

    }

    if(flag==0) fill_square(num+1,square,is_filled,x+1,y+1,n);

  }

}

int main(void) {

  int n;

  int square[15][15];
  int is_filled[15][15];
  
  int i,j;


  while(1) {

    scanf("%d",&n);

    if(n==0) break;

    for(i=0;i<15;i++) for(j=0;j<15;j++) is_filled[i][j]=0;

    square[(n+1)/2][(n-1)/2]=1;

    is_filled[(n+1)/2][(n-1)/2]=1;

    fill_square(2,square,is_filled,(n+3)/2,(n+1)/2,n);

    for(i=0;i<n;i++) {

      for(j=0;j<n;j++) {

	printf("%4d",square[i][j]);

      }

      puts("");

    }

  }

  return 0;

}

    