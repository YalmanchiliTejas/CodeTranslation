#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    int d = min(x,y);
    int ans = 0;
    a+b>2*c ? ans +=2*c*d : ans += d*(a+b);
    if(x-d!=0){
        a>2*c? ans += 2*c*(x-d):ans+= a*(x-d);
    }else if(y-d!=0){
        b>2*c? ans += 2*c*(y-d):ans+= b*(y-d);    
    }
    cout << ans << endl;
    return 0;
}