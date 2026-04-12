#include <iostream>
using namespace std;
int main(void){
   long a,b,c,x,y;
   cin >> a >> b >> c >> x >> y;
   long ans = a * x + b * y;
   for(long i = 1;i <= max(x,y);i++){
        ans = min(ans,c * 2 * i + a * max(0l,x - i) + b * max(0l,y - i));
   }
   cout << ans << endl;
}
