#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
// freopen("input.txt", "r", stdin);
ll nCr(ll n, ll m) {
    if (m > n) return 0;
    ll ans = 1;
    for(ll i = 1; i <= m; i++) {
        ans *= (n+1-i);
        ans /= i;
    }
    return ans;
}
ll sub(string n, int k) {
    int len = n.size();
    ll ans = nCr(len-1, k) * pow(9, k);
    // cout << "step 1 " << ans << endl;
    ans += (n[0] - '1') * nCr(len-1, k-1) * pow(9, k-1);
    k--;
    if (k > 0) {
        for(int i = 1; i < n.size(); i++) {
            if (n[i] != '0') {
                ans += sub(n.substr(i), k);
                break;
            }
        }
    } else {
        ans += 1;
    }
    return ans;
}

int main() {
    string n;
    int k = 0;
    cin >> n >> k;
    cout << sub(n, k) << endl;
    return 0;
}

