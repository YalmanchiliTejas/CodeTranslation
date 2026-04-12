#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  if(n%2==0){
    int x=n-1,y=0;
     for(int i=0;i<n/2;i++){
       cout<<a[x]<<" ";
       x-=2;
     }
     for(int i=0;i<n/2;i++){
       cout<<a[y]<<" ";
       y+=2;
     }
  }else{
    int x=n-1,y=1;
    for(int i=0;i<n/2+1;i++){
      cout<<a[x]<<" ";
      x-=2;
    }
    for(int i=0;i<n/2;i++){
      cout<<a[y]<<" ";
      y+=2;
    }
  }
  cout<<endl;
  return 0;
}
