#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a.at(i);
    ll ans = 0;
    ll sum = 0;
    rep(i, n){
        sum += a.at(i);
        sum %= 1000000007;
    } 
    for(int i = 0; i < n; i++){
        sum -= a.at(i);
        if(sum < 0) sum += 1000000007;
        ans += (ll)a.at(i)*sum;
        ans %= 1000000007;
    }
    cout << ans << endl;
    return 0;
}