#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int main(){
   int a,b,c,x,y;
   int ans=0;
   cin >> a >> b >> c >> x >> y;
   ans = a*x+b*y;
   for (int i=0;i < max(x,y);i++){
      int tmp = a*(x-i-1)+b*(y-i-1)+2*c*(i+1);
      if (x-i-1 < 0 ){
         tmp = b*(y-i-1)+2*c*(i+1);
      }
      else if (y-i-1 < 0){
         tmp = a*(x-i-1)+2*c*(i+1);
      }
      ans=min(ans,tmp);
   }
   cout << ans << endl;
   
   
   
   return 0;
}