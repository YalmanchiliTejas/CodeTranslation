#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18, mod = 1e9 + 7;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    vector<int> a(n);
    int sum = 0;
    for(int&x : a) cin >> x, sum += x;

    for (int x : a) {
        sum -= x;
        ans = (ans + ((x % mod) * (sum % mod))) % mod;
    }

    cout << ans;

}