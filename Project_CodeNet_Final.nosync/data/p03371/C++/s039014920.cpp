#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;


int main(void){
    int a, b, c, x, y, ans;

    cin >> a >> b >> c >> x >> y;

    int k;
    if(2*c < a + b){
        k = min(x, y);
        ans = 2* c * k;
        x = x - k;
        y = y - k;
    }
    if(2*c < a){
        a = 2*c;
    }
    ans = ans + a * x; 
    if(2*c < b){
        b = 2*c;
    }
    ans = ans + b * y;

    cout << ans << endl;
    return 0;
}