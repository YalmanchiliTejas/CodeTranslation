#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,x,y;
  cin >>a>>b>>c>>x>>y;
  int okane=a*x+b*y;
  int hikaku=c*max(2*x,2*y);
  /*if(hikaku<okane){
    cout<<hikaku<<endl;
    return 0;
  }*/
  for(int i=1;i<=max(x*2,y*2);i++){
    if(i%2==1){
      okane=min(okane,c*i+a*(max(0,x-i/2+1))+b*(max(y-i/2+1,0)));
    }else{
      okane=min(okane,c*i+a*(max(x-i/2,0))+b*(max(0,y-i/2)));
    }
  }
  cout<<okane<<endl;
  return 0;
}