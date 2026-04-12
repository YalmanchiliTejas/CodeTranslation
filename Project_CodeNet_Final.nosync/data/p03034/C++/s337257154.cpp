#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t ans=0;
  for(int i=1;i<N-1;i++){
  if((N-1)%i==0){
  int k=(N-1)/i; k-=1; k/=2;
    int64_t a=0;
    for(int j=0;j<=k;j++){
    a+=A.at(i*j)+A.at(N-1-i*j);
      if(ans<a)ans=a;
    }
      }else{
  int64_t a=0;
    for(int j=0;(1+j)*i<N-1;j++){
    a+=A.at(i*j)+A.at(N-1-i*j);
      if(ans<a)ans=a;
    }
  }
  }cout<<ans<<endl;
  return 0;
}