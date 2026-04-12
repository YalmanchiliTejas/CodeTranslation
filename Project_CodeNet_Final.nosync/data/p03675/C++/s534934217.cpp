#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e9
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i, 0, n) cin >> v[i];
    int x = 0;
    if (n % 2 == 1)
        x = 1;
    for (int i = n - 1; i >= 0; i -= 2)
        cout
            << v[i] << " ";
    for (int i = x; i < n; i += 2)
        cout << v[i] << " ";
    cout << endl;
}