#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  
  int n,m;
  int data[20000];

  while(1){
    int max=0;
    cin>>n>>m;
    if(n==0 && m==0) break;
    for(int i=0;i<n+m;i++)
      cin>>data[i];

    sort(data,data+n+m);
    max=data[0];
    for(int i=1;i<n+m;i++){
      if(data[i]-data[i-1]>max)
	max=data[i]-data[i-1];
    }
    cout<<max<<endl;
  }
  return 0;
}