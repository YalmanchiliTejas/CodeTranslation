#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int ans = 0;
    
    //no1
    int temp1 = a * min(x, y) + b * min(x, y);
    int temp2 = c * 2 * min(x, y);
    
    ans += min(temp1, temp2);
    
    int memo = min(x, y);
    x -= memo;
    y -= memo;
    
    //cout << x << y << endl;
    int temp3 = a * x +  b * y;
    int temp4 = c * 2 * max(x, y);
    
    ans += min(temp3, temp4);
    
    cout << ans << endl;
}