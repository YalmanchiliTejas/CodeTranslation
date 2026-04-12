#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 int i,j,n,m;
 scanf("%d%d",&n,&m);

 int a[m+1],b[m+1],path[n+1][n+1],x[n];

 for(i=0;i<n;++i)
  x[i]=i+1;

 for(i=0;i<=n;++i)
  for(j=0;j<=n;++j)
   path[i][j]=0;

 for(i=0;i<m;++i){
  scanf(" %d%d",&a[i],&b[i]);
  path[a[i]][b[i]]=1;
  path[b[i]][a[i]]=1;
 }

 int cnt,ans=0;
 do{
  if(x[0]==1){
   cnt=0;
   for(i=0;i<n-1;++i){
    if(path[x[i]][x[i+1]])
     cnt++;
   }
  if(cnt==n-1)ans++;
  }
 }while(next_permutation(x,x+n));

 printf("%d\n",ans);

return 0;}
