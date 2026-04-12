#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main(){
  ll a,b,c,x,y;
  cin >> a>>b>>c;
  cin >>x>>y;
  ll t=(a+b),sum=0;
  if(t>c*2) {
   if(x<y) {
     sum+=(c*2*x);
     sum+=min((y-x)*b,c*2*(y-x));
   }
   else{
     sum+=(c*2*y);
     sum+=min((x-y)*a,c*2*(x-y));
   }
   cout <<sum<<endl;
  }
  else{
    cout << a*x+b*y<<endl;
  }
}
