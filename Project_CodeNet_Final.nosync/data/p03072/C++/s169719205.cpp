//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
int main (void)
{
  int n,h,max=0,ans=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>h;
    if(h>=max){max=h,ans++;}
  }
  cout<<ans<<endl;

  return 0;
}
