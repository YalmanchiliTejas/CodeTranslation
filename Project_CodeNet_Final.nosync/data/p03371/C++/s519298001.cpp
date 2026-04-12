#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ca = 0, cb = 0;
    ll ans = 0;
    while (ca < x && cb < y)
    {
    ans += min(2 * c, a + b);
    ca++;
    cb++;
    }
    while (ca < x)
    {
    ans += min(2 * c, a);
    ca++;
    }
     while (cb < y)
    {
    ans += min(2 * c, b);
    cb++;
    }
    cout << ans << endl;
    return 0;
}