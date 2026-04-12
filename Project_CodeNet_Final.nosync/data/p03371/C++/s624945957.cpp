#include<iostream>
#include<bits/stdc++.h> 
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans=0;
  if((a+b)/2.0<=c)
    ans+=a*x+b*y;
  else{
    ans+=2*c*min(x,y);
    if(x>y)
      ans+=(x-y)*min(a,2*c);
    else
      ans+=(y-x)*min(b,2*c);
  }
  cout<<ans<<endl;
  return 0;
}