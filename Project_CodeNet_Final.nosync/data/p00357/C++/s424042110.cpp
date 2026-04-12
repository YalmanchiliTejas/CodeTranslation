#include<iostream>
using namespace std;
int main(){
long long a[300002];
int x,y,z;
cin>>x;
for(int i=0;i<x;i++){
  cin>>a[i];
}
if(a[0]>=10&&a[x-1]>=10){
for(int i=1;i<x;i++){
  int f=0;
  if(a[i]<10){
  for(int j=i-1;j>=0;j--){
    if(a[j]>=(i-j)*10+10){
      break;
    }
    if(j==0){
      
      cout<<"no\n";
      return 0;
    }
    
  }
  for(int j=i+1;j<x;j++){
    if(a[j]>=(j-i)*10+10){
      break;
    }
    if(j==x-1){
      cout<<"no\n";
      return 0;
    }
    
  }
  
  
  
  }
}
  
}
else{
cout<<"no\n";
return 0;

}
cout<<"yes\n";
  return 0;
}