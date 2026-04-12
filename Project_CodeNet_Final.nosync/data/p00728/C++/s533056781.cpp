#include<iostream> 
using namespace std; 
int main(){ 
  int n; 
  int t[100],mx,mn,sum; 
  while(1){ 
    cin>>n; 
    if(n==0)break; 
    mx=sum=0; 
    mn=1000; 
    for(int i=0;i<n;i++){ 
      cin>>t[i]; 
      if(mn>t[i])mn=t[i]; 
      if(mx<t[i])mx=t[i]; 
      sum+=t[i]; 
    } 
    sum-=mn; 
    sum-=mx; 
    cout<<sum/(n-2)<<endl; 
      
  } 
  return 0; 
}