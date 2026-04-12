#include <iostream>
#include <algorithm>
#include<vector>
#include <utility>
#include <string>

using namespace std;

int main(){
  int n,a,b,c,i,j,k;
  string s;
  int x,y;
  long long ans=0;
  cin >> a >> b >> c >> x >> y;
  if(a+b>2*c){
    ans+=2*min(x,y)*c;
  }else{
    ans+=min(x,y)*(a+b);
  }
  k=min(x,y);
  x-=k;
  y-=k;
  if(x!=0){
    if(a>2*c){
      ans+=x*2*c;
    }else{
      ans+=a*x;
    }
  }else if(y!=0){
    if(b>2*c){
      ans+=y*2*c;
    }else{
      ans+=b*y;
    }
  }
//  cout << x << " " << y << endl;
  cout << ans << endl;
  return 0;
}
