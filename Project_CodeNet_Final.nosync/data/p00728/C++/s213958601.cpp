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
  int a,n;
  int sm,mx,mn;
  while(cin>>n&&n){
    sm=0;
    mx=0;
    mn=1000;
    for(i=0;i<n;i++){
      cin>>a;
      sm+=a;
      if(mx<a)
	mx=a;
      if(mn>a)
	mn=a;
    }
    cout<<(sm-mn-mx)/(n-2)<<endl;
  }
  return 0;
}