#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const ll mod = 1000000000+7;

int main(){
    int n;  cin >> n;
    vector<ll>a(n);
    rep(i, n)   cin >> a[i];
    vector<ll>sum(n);
    sum[0] = a[0];
    for(int i = 1; i < n; i++){
        sum[i] = sum[i-1] + a[i];
        sum[i] %= mod;
    }
    ll ans = 0;
    rep(i, n-1){
        ll tmp = mod + sum[n-1] - sum[i];
        tmp %= mod;
        tmp *= a[i];
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;
}

