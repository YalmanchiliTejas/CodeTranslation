#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()

using ll = long long;
using ld = long double;
using namespace std;

const ll inf = 2e18;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 5;

int n, a[N];

ll fastpow(ll a, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1)res = (res * a) % m;
        n >>= 1;
        a = (a * a) % m;
    }
    return res;
}
ll add(ll a, ll b, ll m) {
    return (a % m + b % m) % m;
}
ll sub(ll a, ll b, ll m) {
    return ((a - b) % m + m) % m;
}
ll mul(ll a, ll b, ll m) {
    return (a % m * b % m) % m;
}
ll div(ll a, ll b, ll m) {
    return mul(a, fastpow(b, m - 2, m), m);
}

ll findProductSum()
{
    // calculating array sum (a1 + a2  ... + an)
    ll array_sum = 0;
    for (int i = 0; i < n; i++)
        array_sum = add(array_sum, a[i], mod);

    // calcualting square of array sum
    // (a1 + a2 + ... + an)^2
    ll array_sum_square = mul(array_sum, array_sum, mod);

    // calcualting a1^2 + a2^2 + ... + an^2
    ll individual_square_sum = 0;
    for (int i = 0; i < n; i++)
        individual_square_sum = add(individual_square_sum, mul(a[i], a[i], mod), mod);

    // required sum is (array_sum_square -
    // individual_square_sum) / 2
    return div(sub(array_sum_square, individual_square_sum, mod), 2, mod);
}

void code() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << findProductSum() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin>>t;

    while (t-- > 0) {
        code();
    }
}