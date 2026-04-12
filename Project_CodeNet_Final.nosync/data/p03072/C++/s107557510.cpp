#include<iostream>

using namespace std;

int main(){
  int n;
  cin>>n;
  int h[20];
  for(int i=0;i<n;i++){
    cin>>h[i];
  }
  
  int now=h[0];
  int ans=1;
  for(int i=1;i<n;i++){
    if(now<=h[i]){
      now=h[i];
      ans++;
    }
  }
  
  cout<<ans;
}