#include <bits/stdc++.h>

#define pb push_back
#define PQ priority_queue
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

typedef long long ll;
typedef long double ld;

//__builtin_popcount(x)

using namespace std;

/*const int mod = 1e9 + 7;

ll add(ll a, ll b) {
    ll res = a + b;
    if (res >= mod) res -= mod;
    return res;
}

ll sub(ll a, ll b) {
    ll res = a - b + mod;
    if (res >= mod) res -= mod;
    return res;
}

ll mul(ll a, ll b) {
    return (((a % mod) * (b % mod)) % mod);
}*/

/*vector<int> find_dividers(int x) {
    vector<int> dividers;

    for (int i = 1; i <= sqrt(x); i++) {
        if (x % i == 0) {
           dividers.push_back(i);
            if (i * i != x) {
                dividers.push_back(x / i);
            }
        }
    }

    return dividers;
}*/

/*int nok(int a, int b) {
    return a / __gcd(a, b) * b;
}*/

void solve() {
    int n;
    cin >> n;
    cout << ((n < 30) ? "No" : "Yes") << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
