#include<stdio.h>
int main(){
  int a[30000],i,j,n,m,st,max;
  while(1){
    max=0;
      a[0]=0;
    scanf("%d%d",&n,&m);
    if(n==0 && m==0)break;
    for(i=1;i<n+1;i++){
      scanf("%d",&a[i]);
    }
    for(i=0;i<m;i++){
      scanf("%d",&a[i+n+1]);
    }
    for(i=0;i<n+m+1;i++){
      for(j=1;j<n+m+1;j++){
	if(a[j-1]>a[j]){
	  st=a[j-1];
	  a[j-1]=a[j];
	  a[j]=st;
	}
      }
    }
    for(i=1;i<n+m+1;i++){
      if(a[i]-a[i-1]>max)max=a[i]-a[i-1];
    }
    printf("%d\n",max);
  }
  return 0;
}