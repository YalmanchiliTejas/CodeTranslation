#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
typedef long long ll;
typedef vector<ll> vl;
#define rp(i, f, t) for (int i = f; i < t; i++)
#define pr(i, f, t) for (int i = t - 1; i >= f; i--)
#define ca(n, a) rp(ca_i, 0, n) cout << a[ca_i] << ((ca_i == n - 1) ? "\n" : " ")
#define za(n, a) rp(za_i, 0, n) a[za_i] = 0
#define be(a) a.begin(), a.end()
int main()
{
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}