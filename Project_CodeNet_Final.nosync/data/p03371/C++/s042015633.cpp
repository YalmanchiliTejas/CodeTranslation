#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int sum=0;
  int ans=0;
  int a,b,c,x,y;
  cin >> a >> b >>c >>x >> y;
  int n=(a+b)/2;
  int d=min(x,y);
  if(x>y){
    ans+=(x*c*2);
  }
  else{
    ans+=(y*c*2);
  }
if(n>c){
  sum+=(d*c*2);
  x-=d;y-=d;
  sum+=((x*a)+(y*b));
  sum=min(ans,sum);
}
else{
  sum+=(a*x);
  sum+=(b*y);
  sum=min(ans,sum);
}
cout << sum << endl;
}
