#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

// arr[i] - par*n + (k-par)*1 <= n-1
// arr[i] - n + 1 <= n*par - k + par
// par >= (arr[i]-n+k+1) / (n+1)

// => arr[i]-n+k+1 >= 0
// => k >= n-1-arr[i]

// arr[i] - par*n + (k-par)*1 >= 0
// arr[i] + k >= (n+1) * par
// par <= arr[i]+k / (n+1)

ll bs(vector<ll>& arr, ll k, ll n) {
    ll ops = 0;
    for(ll& val: arr) {
        ll tmp = (val-n+k+1 <= 0) ? 0 : (1 + (val-n+k+1-1) / (n+1));
        // cout << "=>" << tmp << " ";
        ops += tmp;
    }
    // cout << "k = " << k << ", ops = " << ops << endl;
    return ops;
}
int main() {
    int n;
    cin >> n;
    vector<ll> arr(n, 0);
    for(ll& val: arr)
        cin >> val;
    // ll m = *min_element(arr.begin(), arr.end());
    // ll l = max(n-1-m, 0LL);
    ll l = 0;
    ll r = 8e18+ 7;
    for(int i = 0; i < 40; i++)
        bs(arr, i, n);
    while (l+2400 < r) {
        ll mid = l + (r-l)/2;
        ll ops = bs(arr, mid, n);
        if (ops > mid) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    for(ll i = max(0LL, l-1200); i <= r; i++) {
        if (bs(arr, i, n) == i) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}


