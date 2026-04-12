#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    cin >> n;
    vector<ll> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ret = 0, cnt;
    bool flag = 1;
    while(flag) {
        for(i = 0; i < n; i++) {
            if(a[i] >= n) {
                cnt = a[i] / n;
                ret += cnt;
                a[i] %= n;
                for(j = 0; j < n; j++) {
                    if(j != i) {
                        a[j] += cnt;
                    }
                }
            }
        }
        flag = false;
        for(i=0;i<n;i++){
            if(a[i]>=n)flag = true;
        }
    }
    cout << ret << endl;
    return 0;
}