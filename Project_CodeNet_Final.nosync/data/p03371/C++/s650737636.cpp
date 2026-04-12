#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y; cin>>a >>b >>c >>x >>y;
  int ans=INT_MAX;
  for(int i=0;i<=100000;i++){
    int money=i*2*c+max(0,x-i)*a+max(0,y-i)*b;
    ans=min(ans,money);
  }
  cout<<ans<<endl;
}