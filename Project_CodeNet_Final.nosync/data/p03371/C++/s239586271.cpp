#include<iostream>
using namespace std;
int main(){
  int a,b,c,x,y,ans=1001001001;
  cin>>a>>b>>c>>x>>y;
  for(int i=0;i<=x+y;i++){
    long long int min=i*2*c+max(0,x-i)*a+b*max(0,y-i);
    if(min<ans) ans=min;
  }
  cout<<ans<<endl;
  return 0;
}