#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using Graph = vector<vector<int>>;
using ll = long long;
using p = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);

    rep(i, n)
    {
        cin >> a[i];
    }

    vector<ll> s(n + 1, 0);
    ll amari = 0;
    for (int i = 0; i < n; ++i)
    {
        s[i + 1] = s[i] + a[i];
    }

    rep(i, n)
    {
        ll b = (s[n] - s[i + 1]) % 1000000007;
        amari += b * (a[i] % 1000000007) % 1000000007;
        amari = amari % 1000000007;
    }

    cout << amari << endl;
}