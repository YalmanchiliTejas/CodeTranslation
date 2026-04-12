#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

ll n , p , m;

int main()
{
    _FastIO;

    cin >> n >> p >> m;
    vector<ll> used(m + 10 , 0);
    vector<ll> v(m + 10 , 0);
    vector<ll> ms(m + 10 , 0);
    used[p] = 1;
    v[1] = p;
    ms[1] = p;
    ll t = p;
    ll k = 0;
    ll tp = 0;
    ll s = 0;
    for(ll i = 2; i <= m + 5; i++){
        ll x = (t * t) % m;
        t = x;
        ms[i] = t;
        if(used[t]){
            k = i - used[t];
            tp = used[t] - 1;
            s = v[i - 1] - v[tp];
            break;
        }
        used[t] = i;
        v[i] = v[i - 1] + t;
    }
    ll ans = v[tp];
    if(n <= tp){
        cout << v[n] << endl;
        return 0;
    }
    n -= tp;
    ll kp = n / k;
    ll kq = n % k;
    ans += (kp * s);
    ans += (v[tp + kq] - v[tp]);
    cout << ans << endl;
    return 0;
}
