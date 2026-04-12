#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int inf = 1e9;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans;
    if(a+b <= 2*c) ans = a*x + b*y;
    else{
        if(x >= y) ans = min(2*c*x, 2*c*y+a*(x-y));
        else ans = min(2*c*y,2*c*x+b*(y-x));
    }
    cout << ans << endl;

}
