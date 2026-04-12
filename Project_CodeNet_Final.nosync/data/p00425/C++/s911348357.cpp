#include<iostream>
using namespace std;
int main() {
  int n,w,t,i,m,sum;
  string s;
  while(1){
    cin>>i;
    n=2,w=3,t=1;
    sum=1;
    if(i==0)break;
    for(int j=0;j<i;j++){
      cin>>s;
      if(s=="South")m=n,n=t,t=7-m;
      if(s=="North")m=t,t=n,n=7-m;
      if(s=="East")m=t,t=7-w,w=m;
      if(s=="West")m=t,t=w,w=7-m;
      if(s=="Left")m=w,w=n,n=7-m;
      if(s=="Right")m=n,n=w,w=7-m;
      sum+=t;
    }
    cout<<sum<<"\n";
  }
}