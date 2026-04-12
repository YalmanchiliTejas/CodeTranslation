#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y, z, ans;
    cin >> a >> b >> c >> x >> y;
    z = (x > y)? (x-y)*a : (y-x)*b;
    ans = min(a*x + b*y, min(2*c*max(x,y), z + 2*c*min(x, y)));
    cout << ans;
}