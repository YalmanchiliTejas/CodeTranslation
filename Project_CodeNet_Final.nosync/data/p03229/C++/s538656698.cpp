#include<stdio.h>
#include<stdlib.h>
int desc(const void *a, const void *b){
  return *(int*)b - *(int *)a;
}
int main(){
  int n,i;
  long long int tmp=0,ans=0;
  scanf("%d",&n);
  int a[n],b[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  qsort(a,n,sizeof(int),desc);
  for(i=0;i<n;i++){
    if(i%2==0)b[i]=1;
    else b[i]=-1;
    if(i!=0 && i!=n-1)b[i]*=2;
  }
  qsort(b,n,sizeof(int),desc);
  for(i=0;i<n;i++){
    ans+=a[i]*b[i];
  }
  for(i=0;i<n;i++){
    tmp+=a[i]*(-1*b[n-1-i]);
  }
  printf("%lld\n",((tmp<ans)?ans:tmp));
  return 0;
}