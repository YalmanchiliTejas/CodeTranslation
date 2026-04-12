#include<bits/stdc++.h>
using namespace std;
#define lp(i,n) for(int i=0;i<n;i++)
#define lpin(a,i,n) for(int i=0;i<n;i++){cin>>a[i];}


int main(){
  int a[100];
  lp(i,100){
    a[i]=0;
  }
  int count=0;
  lp(i,12){
    int x;
    cin>>x;
    a[x]++;
    if(a[x]%4==0) count++;
  }
  if(count==3) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
    
	  
  return 0;
}

