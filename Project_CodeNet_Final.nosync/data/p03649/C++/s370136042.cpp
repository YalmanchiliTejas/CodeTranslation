#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 998244353
using namespace std;
ll solve(vector<ll> &a) {
    ll res = 0, n = a.size();
    while(*max_element(all(a)) >= n) {
        *max_element(all(a)) -= n + 1;
        for(int i = 0; i < n; i++) {
            a[i]++;
        }
        res++;
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, kai = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    kai = sum - n * (n - 1);
    if(kai <= 0) {
        cout << solve(a) << endl;
    } else {
        for(ll i = kai; i < sum; i++) {
            ll tmp = 0;
            for(int j = 0; j < n; j++) {
                ll x = a[j] + i;
                tmp += (x + 1) / (n + 1);
            }
            if(tmp == i) {
                cout << tmp << endl;
                return 0;
            }
        }
        cout << "fuck" << endl;
    }
}