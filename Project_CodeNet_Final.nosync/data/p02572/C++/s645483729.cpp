#include <algorithm>
#include <bitset>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long
#define pb push_back
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

const ll mod = 1000000007;

ll sub(ll a, ll b) {
    ll ans = (a%mod - b%mod + mod)%mod;
    return ans;
}

ll power(ll a, ll n) {
    if(n == 0) return 1;
    else if(n%2 == 0) {
        return power((a%mod*a%mod)%mod, n/2)%mod;
    }
    else return (a%mod * power((a%mod * a%mod), (n-1)/2)%mod)%mod;
}

ll divi(ll a, ll b) {
    ll inv = power(b, mod-2LL);
    ll ans = (a%mod * inv%mod)%mod;
    return ans;
}

ll findProductSum(ll A[], ll n)
{
    // calculating array sum (a1 + a2  ... + an)
    ll array_sum = 0;
    for (ll i = 0; i < n; i++)
        array_sum = (array_sum%mod + A[i]%mod)%mod;

    // calcualting square of array sum
    // (a1 + a2 + ... + an)^2
    ll array_sum_square = (array_sum%mod * array_sum%mod)%mod;

    // calcualting a1^2 + a2^2 + ... + an^2
    ll individual_square_sum = 0;
    for (ll i = 0; i < n; i++) {
        individual_square_sum += (A[i]%mod*A[i]%mod)%mod;
        individual_square_sum %= mod;
    }

    // required sum is (array_sum_square -
    // individual_square_sum) / 2
    ll ret = sub(array_sum_square, individual_square_sum);
    ret = divi(ret, 2LL);
    return ret;
}

void solve() {
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i<n; i++) cin >> a[i];
    ll ans = findProductSum(a, n);
    cout << ans << '\n';
}

int main() {_
    int t = 1;
//    cin >> t;
    for(int i = 1; i<=t; i++) {
        solve();
    }
    return 0;
}
