#include<vector>
#include<list>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
  int i,j;
  int a[100001],b[100001],p,n;
  int sm;
  a[0]=1;
  while(cin>>n&&n){
    memset(b,0,sizeof(b));
    j=0;
    for(i=1;i<n+1;i++){
      cin>>p;
      if(i%2){
	if(a[j]==-p)
	  b[j]++;
	else{
	  j++;
	  a[j]=-p;
	  b[j]=1;
	}  
      }else{
	if(a[j]==-p)
	  b[j]++;
	else{
	  b[j]++;
	  if(a[j-1]==-p){
	    j--;
	    a[j]=-p;
	    b[j]+=b[j+1];
	  }else
	    a[j]=-p;
	}
      }
    }
    sm=0;
    for(i=1;i<j+1;i++){
      if(a[i]==0)
	sm+=b[i];
    }
    cout<<sm<<endl;
  }
  return 0;
}