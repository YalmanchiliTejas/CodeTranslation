#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    long long ans;
    if(a+b<2*c){
        ans = a*x+b*y;
    }
    else {
        ans = 2*c*min(x, y);
        if(x>y){
            if(a<2*c) ans += a*(x-y);
            else ans += 2*c*(x-y);
        }
        else {
            if(b<2*c) ans += b*(y-x);
            else ans += 2*c*(y-x);
        }
    }
    cout << ans << endl;
    return 0;
}