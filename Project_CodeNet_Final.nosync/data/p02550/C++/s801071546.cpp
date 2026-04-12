#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll c[100002];
ll d[100002];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = x;
    c[x] = (ll)1;
    d[1] = x;
    n -= (ll)1;
    ll start = (ll)1;

    while(n > 0){
        ll y = (x * x) % m;
        if(c[y] == 0){
            c[y] = ++start;
            d[c[y]] = d[c[y] - 1] + y;
            ans += y;
        }else{
            ll dif = (d[start] - d[c[y] - 1]);
            ll cnt = (start - c[y] + (ll)1);

            ans += (n / cnt) * dif;
            n %= cnt;

            for(int j = 0; j < n; j++){
                ans += y;
                y = (y * y) % m;
            }
            break;
        }
        x = y;
        n -= (ll)1;
    }

    cout << ans << '\n';
}
