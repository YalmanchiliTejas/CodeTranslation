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
  int i;
  int a[6],n;
  int sm;
  while(cin>>n&&n){
    a[0]=1;
    a[1]=2;
    a[2]=3;
    a[3]=5;
    a[4]=4;
    a[5]=6;
    sm=1;
    for(i=0;i<n;i++){
      string s;
      cin>>s;
      if(s=="North"){
	swap(a[3],a[0]);
	swap(a[0],a[1]);
	swap(a[1],a[5]);
      }else if(s=="East"){
	swap(a[2],a[0]);
	swap(a[0],a[4]);
	swap(a[4],a[5]);
      }else if(s=="West"){
	swap(a[4],a[0]);
	swap(a[0],a[2]);
	swap(a[2],a[5]);
      }else if(s=="South"){
	swap(a[1],a[0]);
	swap(a[0],a[3]);
	swap(a[3],a[5]);
      }else if(s=="Right"){
	swap(a[4],a[1]);
	swap(a[1],a[2]);
	swap(a[2],a[3]);
      }else if(s=="Left"){
	swap(a[2],a[1]);
	swap(a[1],a[4]);
	swap(a[4],a[3]);
      }
      sm+=a[0];
    }
    cout<<sm<<endl;
  }
  return 0;
}