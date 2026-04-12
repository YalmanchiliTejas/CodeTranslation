#include<iostream>
using namespace std;
int main(){
  int n,h,max_n=0,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h;
    if(max_n<=h)ans++;
    max_n=max(max_n,h);
  }
  cout<<ans<<endl;
  return 0;
}