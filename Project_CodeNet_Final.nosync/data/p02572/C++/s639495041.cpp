#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long int;
const ll MOD = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        sum %= MOD;
    }
    for(int i = 0; i < n; i++){
        sum -= a[i];
        sum += MOD;
        sum %= MOD;
        ll coans = sum;
        coans *= a[i];
        coans %= MOD;
        ans += coans;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}