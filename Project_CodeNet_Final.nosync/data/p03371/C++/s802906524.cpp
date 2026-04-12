#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    ans += min(x, y)*min(a+b, 2*c);
    ans += fdim(x, y)*min(a, 2*c) + fdim(y, x)*min(b, 2*c);
    cout << ans << endl;
    return 0;
}