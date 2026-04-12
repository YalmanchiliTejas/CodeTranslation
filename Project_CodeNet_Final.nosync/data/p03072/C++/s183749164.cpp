#include<iostream>
using namespace std;

int main(){
  int s=0,i,n;
  cin>>n;
  int a[n];
  
  for(i=0;i<n;i++) cin>>a[i];
  for(i=0;i<n;i++){
    int j=0;
    while(a[j]<=a[i]){
      if(j==i){
        s++;
        break;
      }
      j++;
    }
  }
  
  cout<<s<<endl;
  return 0;
}