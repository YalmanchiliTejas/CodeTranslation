#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n, x, m, r, p;
    cin >> n >> x >> m;
    p = x;
    r = x;
    ll ans = 0, cnt = 0;
    set<ll> s, t;
    while(true){
        if(s.find(x) != s.end())
            break;
        s.insert(x);
        x = x * x % m;
    }
    while(r != x){
        ans += r;
        r = r * r % m;
        cnt++;
    }
    if(cnt >= n){
        ans = 0;
        for(ll i = 0; i < n; i++){
            ans += p;
            p = p * p % m;
        }
        cout << ans << endl;
        return 0;
    }
    ll l = 0, part_sum = 0;
    while(true){
        if(t.find(x) != t.end())
            break;
        t.insert(x);
        l++;
        part_sum += x;
        x = x * x % m;
    }
    n -= cnt;
    ans += (n / l) * part_sum;
    for(ll i = 0; i < n % l; i++){
        ans += x;
        x = x * x % m;
    }
    cout << ans << endl;
    return 0;
}