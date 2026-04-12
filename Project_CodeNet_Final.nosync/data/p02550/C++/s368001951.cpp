#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
ll MOD = 998244353;
int main() {
    ll n,x,m,ans;
    ans = 0;
    cin >> n >> x >> m;
    map<ll,ll>mp;
    ll a = x;
    ll c = 1;   //項数
    mp[a] = c;  //a初出がc
    ll start = 0;
    vector<ll>v;
    v.push_back(a);
    bool b = true;
    while (b) {
        c++;
        a = (a*a)%m;
        v.push_back(a);
        if (mp[a] != 0) {
            start = mp[a];
            b = false;
        }else{
            mp[a] = c;
        }
    }
    ll s,t,u;
    s = t = u =0;
    a = x;
    for (ll i = 1; i <= start-1 && i <= n; i++) {
        s += v[i-1];
    }
    for (ll i = start; i <= c - 1; i++) {
        t += v[i-1];
    }
    for (ll i = 0; i<(n-start+1)%(c-start); i++) {
        u += v[start+i-1];
    }
//    cout << c << endl;
//    cout << start << endl;
//    cout << s << endl;
//    cout << t << endl;
//    cout << u << endl;
    cout << s + (ll)((n-start+1)/(c-start))*t + u << endl;
    return 0;
}

