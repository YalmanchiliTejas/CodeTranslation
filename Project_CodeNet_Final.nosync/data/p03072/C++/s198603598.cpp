#include<iostream>
using namespace std;

int main(){
  int N; cin>>N;
  int ans=0;
  int h[20];
  bool x=true;
  for(int i=0;i<N;i++){
    cin>>h[i];
  }
  for(int i=0;i<N;i++){
    x=true;
    for(int j=0;j<=i;j++){
      if(h[i]-h[j]<0){
        x=false;
      }
    }
    if(x){
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}