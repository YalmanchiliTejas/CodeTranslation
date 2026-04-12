#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = max(a,max(b,c))*(x+y);
    int maxxy = max(x,y);
    rep(i,maxxy+1){
        int cost = max(0,(x-i))*a+max(0,(y-i))*b+(2*i)*c;
        ans = min(ans,cost);
    }
    cout << ans << endl;
}
