#include<bits/stdc++.h>
using namespace std;

int main(void){
    int a, b, c, x, y, ans = 0;
    cin >> a >> b >> c >> x >> y;
    ans = min(x*a+y*b, min(max(x, y)*2*c, min(x*2*c+max(0, y-x)*b, y*2*c+max(0, x-y)*a)));
    cout << ans << endl;
}