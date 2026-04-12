#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF (long long)(1e9+7)
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)

int main(void)
{
    ll a,b,c,x,y;
    ll min_p = INF * 10000000;
    cin >> a >> b >> c >> x >> y;
    for(ll i = 0; i <=  max(x, y) ; i ++) {
        ll p = max(x - i, (long long)0) * a + max(y - i, (long long)0) * b + i * c * 2;
        min_p = min(min_p, p);
    }
    cout << min_p << endl;
         
}
