#include <bits/stdc++.h>
using namespace std;


int main() {
long int N,X,M;
  cin >>N>>X>>M;
  if(M>1){vector<long int>vec(2*M);
  vec.at(0)=X%M;
  for(long int i=1;i<=2*M-1;i++){
  long int k=vec.at(i-1)%M;
  long int l=(k*k)%M;
    vec.at(i)=l;
  }
  long int s=0;
  long int t=0;
  for(long int p=0;p<2*M-2;p++){
    if(s>0){break;}
  for(long int q=p+1;q<2*M-1;q++){
    if(vec.at(p)==vec.at(q)){
    s=p;
      t=q;
    break;}
  }}
  long int r=t-s;
  
  long int a=0;
  if(r>1){
  for(long int b=s;b<t;b++){
  a+=vec.at(b);
  }}else{a=vec.at(s);}
 
  long int A=0;
  for(long int w=0;w<s;w++){A+=vec.at(w);}
  
  long int f=0;
  f=(N-s)/r;

  
  long int d=0;
  if((N-s)%r!=0){
  for(long int y=s;y<=s+(N-s)%r-1;y++){d+=vec.at(y);}}
  A+=a*f+d;
cout<<A<<endl;}
  else if(M==1){
                cout<<0<<endl;}
}