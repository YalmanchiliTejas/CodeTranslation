#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std ;
int main(){
 for(;;){
  int n,s,a=1,b=2,c=3,d=4,e=5,f=6,x;
  string m; 
    s=1;
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++){
    cin>>m;
    if(m=="North"){
      x=e;
      e=a;
      a=b;
      b=f;
      f=x; 
      s=s+a;
    }
    if(m=="East"){
      x=c;
      c=a;
      a=d;
      d=f;
      f=x;
      s=s+a;
    }
    if(m=="West"){
      x=d;
      d=a;
      a=c;
      c=f;
      f=x;
      s=s+a;
    }
    if(m=="South"){
      x=b;
      b=a;
      a=e;
      e=f;
      f=x; 
      s=s+a;
    }
    if(m=="Right"){
      x=b;
      b=c;
      c=e;
      e=d;
      d=x; 
      s=s+a;
    }
    if(m=="Left"){
      x=b;
      b=d;
      d=e;
      e=c;
      c=x;
      s=s+a;
    }
   }
    cout<<s<<endl;
  }
  return 0;
  }