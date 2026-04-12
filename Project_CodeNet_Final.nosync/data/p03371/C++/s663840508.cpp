#include <iostream>
using namespace std;
int main(){
    long a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    long ans = a*x + b*y;
    if(x>=y){
        ans = min(2*c*x,ans);
        ans = min(2*c*y+(x-y)*a,ans);
    }
    else{
        ans = min(2*c*x+(y-x)*b,ans);
        ans = min(2*c*y,ans);
    }
    cout << ans << endl;
}