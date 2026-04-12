#include<iostream>
using namespace std;

int main(){
  int n,i,j;
  int ans=1,max=0;
  cin>>n;
  int h[n];
  for(i=0;i<n;i++){
    cin>>h[i];
  }
  for(i=1;i<n;i++){
    if(h[i-1]>max)max=h[i-1];
    if(max<=h[i])ans++;
  }
  cout<<ans<<endl;
  return 0;
}