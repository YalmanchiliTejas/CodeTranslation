#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int N,mx=0,ans=0;
  cin>>N;
  int H[N];
  for(int i=0; i<N; ++i) cin>>H[i];
  for(int i=0; i<N; ++i){
    if(mx<=H[i]){
      mx=H[i];
      ans ++;
    }
  }
  cout<<ans<<endl;
}