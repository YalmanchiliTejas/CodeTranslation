#include<iostream>
using namespace std;
main(){
  int n,count=0,s,maxs,mins;
  while(1){
    cin>>n;
    if(n==0)break;
    cin>>s;
    count=count+s;
    maxs=s;
    mins=s;
    for(int i=1;i<n;i++){
      cin>>s;
      count=count+s;
      if(s>maxs){
	maxs=s;
      }
      else if(mins>s){
	mins=s;
      }
    }
    cout<<(count-maxs-mins)/(n-2)<<endl;
    count=0;
  }
}