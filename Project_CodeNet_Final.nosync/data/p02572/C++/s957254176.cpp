#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <bitset>
using namespace std;
using ll = long long;
constexpr ll INF = 1010000000000000017LL;
constexpr ll mod = 1000000007;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
    int n;cin>>n;
    ll a[n];
    rep(i,n) cin>>a[i];
    ll sum = 0;
    for(int i = 0; i < n; ++i) sum += a[i];
    // cout<<sum<<endl;

    ll res = 0;
    rep(i,n) {
        sum -= a[i];
        res += (sum%mod) * a[i];
        res %= mod;
    }
    cout<<res<<endl;
}
