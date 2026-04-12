#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int main()
{
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;
    if(x < y){
        swap(x, y);
        swap(a, b);
    }
    ll ans = min(a + b, 2 * c) * min(x, y) + min(a, 2 * c) * (x - y);
    cout << ans << endl;
}