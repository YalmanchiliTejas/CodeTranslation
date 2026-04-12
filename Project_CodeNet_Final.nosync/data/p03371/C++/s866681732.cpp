#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359
#define rep(i,n) for(int i=0;i<(n);i++)
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
    int a, b, c, x, y;
    ll ans = 0, hoge = 0;
    cin >> a >> b >> c >> x >> y;
    ans = a * x + b * y;
    if(x<y){
        hoge = 2 * c * x + b * (y - x);
        hoge = min(hoge, (ll)(2 * c * y));
    }
    else
    {
        hoge = 2 * c * y + a * (x - y);
        hoge = min(hoge, (ll)(2 * c * x));
    }
    ans = min(ans, hoge);
    cout << ans << endl;
    return 0;
}