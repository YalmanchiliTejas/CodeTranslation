#include<iostream>
#include<string>
using namespace std;

int main(){

  for( ; ; ){

  int n,a,b,c,d,e,f,X,A,i;

  a=1;
  b=2;
  c=3;
  d=4;
  e=5;
  f=6;
  A=1;
  i=0;

  string N;

  cin>>n;

  if(n==0)break;

  for(i=0;i<n;i++){
     cin>>N;
     if(N=="North"){
       X=a;
       a=b;
       b=f;
       f=e;
       e=X;
       A=A+a;
     }
     if(N=="East"){
       X=a;
       a=d;
       d=f;
       f=c;
       c=X;
       A=A+a;
     }
     if(N=="West"){
       X=a;
       a=c;
       c=f;
       f=d;
       d=X;
       A=A+a;
     }
     if(N=="South"){
       X=a;
       a=e;
       e=f;
       f=b;
       b=X;
       A=A+a;
     }
     if(N=="Right"){
       X=b;
       b=c;
       c=e;
       e=d;
       d=X;
       A=A+a;
     }
     if(N=="Left"){
       X=b;
       b=d;
       d=e;
       e=c;
       c=X;
       A=A+a;
     }
   }
   cout<<A<<endl;
  }
  return 0;
}