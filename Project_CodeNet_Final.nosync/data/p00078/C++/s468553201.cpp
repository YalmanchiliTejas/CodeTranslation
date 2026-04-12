#include "bits/stdc++.h"
using namespace std;
using namespace std;
int context[15][15];
void init(){
  for(int i=0;i<15;i++){
    for(int j=0;j<15;j++){
      context[i][j]=0;
    }
  }
}
int main(){
  int n,nowx,nowy;
  while(cin>>n,n){
    init();
    nowx=n/2; nowy=n/2+1;
    context[nowy][nowx]=1;
    for(int i=2;i<=n*n;i++){
      nowx++; nowy++;
      while(true){
	if(nowx>=n) nowx=0;
	if(nowx<0) nowx=n-1;
	if(nowy>=n) nowy=0;
	if(context[nowy][nowx]!=0) nowx--,nowy++;
	if(context[nowy][nowx]==0 && 0<=nowx && nowx<n && 0<=nowy && nowy<n) break;
      }
      context[nowy][nowx]=i;
      //      printf("(%d,%d)\n",nowy,nowx);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	printf("%4d",context[i][j]);
      }
      cout<<endl;
    }
  }
}