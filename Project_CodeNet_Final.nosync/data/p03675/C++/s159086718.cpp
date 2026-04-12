#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=n-1;i>=0;i-=2){
    cout<<a[i]<<" ";
  }
  if(n%2==0){
    for(int i=0;i<n;i+=2){
      cout<<a[i]<<" ";
    }
  }else{
    for(int i=1;i<n;i+=2){
      cout<<a[i]<<" ";
    }
  }
}