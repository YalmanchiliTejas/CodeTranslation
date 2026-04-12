//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    int k;
    cin >> n >> k;

    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(i <= k) continue;
        ll num = n/i;
        ans += num * (i-k);
        int nn = n%i;
        if(nn >= k) {
            ans += 1+nn-k;
            if(k==0) ans--;
        }
    }

    cout << ans << endl;
}