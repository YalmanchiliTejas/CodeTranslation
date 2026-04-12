#include <bits/stdc++.h>
using namespace std;

int main(){
 long long a,b,c,x,y,sum;
  cin >> a >> b >> c >> x >> y;
  int xymax=max(x,y);
  int xymin=min(x,y);
  long long ans=a*x+b*y;
  int ians;
  for(int i=0;i<=2*xymax;i=i+2){
    sum=0;
    sum+=i*c;//iはABを買う個数
    if(xymin<i/2){
      if(x<=y)sum+=b*(y-i/2);
      if(x>y)sum+=a*(x-i/2);
    }
    else{
    sum+=a*(x-i/2);
    sum+=b*(y-i/2);
    }
    ans=min(ans,sum);

    }
  cout << ans << endl;
}