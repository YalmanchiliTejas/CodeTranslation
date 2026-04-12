#include<stdio.h>
void sort(int k[4],int a[6]){
  int w,i;
  //for(i=0;i<6;i++)printf("%d ",a[i]);
  //printf("\n");
  w=a[k[0]-1];
  for(i=0;i<3;i++){
    a[k[i]-1]=a[k[i+1]-1];	
  }
  a[k[3]-1]=w;
  //for(i=0;i<6;i++)printf("%d ",a[i]);
  //putchar('\n');
}


int main(void){
  //int a[6]={1,2,3,4,5,6};
  int w[4]={1,3,6,4};
  int e[4]={1,4,6,3};
  int n[4]={1,2,6,5};
  int s[4]={1,5,6,2};
  int r[4]={2,3,5,4};
  int l[4]={2,4,5,3};	
  char in[30];
  int m;
  int i,j,t;
  while(scanf("%d",&m),m){
    int a[6]={1,2,3,4,5,6};
    int sum=1;
    for(i=0;i<m;i++){
      scanf("%s",in);
      if(in[0]=='N')sort(n,a);
      else if(in[0]=='N')sort(n,a);
      else if(in[0]=='W')sort(w,a);
      else if(in[0]=='S')sort(s,a);
      else if(in[0]=='E')sort(e,a);
      else if(in[0]=='R')sort(r,a);
      else if(in[0]=='L')sort(l,a);
      sum+=a[0];
    }
    printf("%d\n",sum);
  }
}