#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
using namespace std;
//#include <stdio.h>

 
int main(void)
{
    long long a, b, c, x, y, ans = 0, nokori;
    cin >> a >> b >> c >> x >> y;
    nokori = abs(x - y);
    
    if(a + b < c * 2) 
        ans += min(x, y) * (a + b);
    else
        ans += min(x, y) * c * 2;
    
    if(x > y){
        if(a < c * 2)
            ans += a * nokori;
        else
            ans += c * 2 * nokori;
    }
    else{
        if(b < c * 2)
            ans += b * nokori;
        else
            ans += c * 2 * nokori;
    }

    cout << ans << endl;
}