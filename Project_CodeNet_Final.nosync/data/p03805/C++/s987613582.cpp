#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
  int d[10],n,m,a[10][10],i,j,b,c,ans=0,k=0;
  scanf("%d %d\n",&n,&m);
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<m;i++){
    scanf("%d %d\n",&b,&c);
    a[b][c]=1,a[c][b]=1;
  }
  for(i=0;i<n;i++){
    d[i]=1+i;
  }
  do{
    if(d[0]==1){
    for(i=0;i<n-1;i++){
      if(a[d[i]][d[i+1]]==0){
        k=1;
        break;
      }
    }
    if(k==0){
      ans++;
    }
    k=0;
    }
  }while(next_permutation(d,d+n));
  printf("%d\n",ans);
  return 0;
}