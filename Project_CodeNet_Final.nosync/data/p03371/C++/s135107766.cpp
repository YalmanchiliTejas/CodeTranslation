#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 0;
    if(x>y){
        ans = 2 * c * y + a * (x - y);
    }
    else{
        ans = 2 * c * x + b * (y - x);
    }
    cout << min({a * x + b * y, c * 2 * max(x, y), ans});
}