#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <algorithm>

/*
#include <atcoder/all>
using namespace atcoder;
*/

using namespace std;

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define repr(i, n) for (ll i = n - 1; i >= 0; i--)
#define repr1(i, n) for (ll i = n; i > 0; i--)
#define FOR(i, j, n) for (ll i = j; i < n; i++)

const ll MOD = 1000000007; // 10^9+7
const ll MOD2 = 998244353;
const ll INF = 10000000000;

int main(void){
    int n;
    cin >> n;
    vector<ll> a(n,0);
    rep(i,n) cin >> a[i];

    deque<int> ans;
    rep(i,n){
        if(i % 2 == n % 2 ) ans.push_back(a[i]);
        else ans.push_front(a[i]);
    }

    rep(i,n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}