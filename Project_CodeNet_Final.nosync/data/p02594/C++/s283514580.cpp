#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define PI 3.14159265359
#define sz(c) (int)c.size()
#define len(c) (int)c.length()
#define hcf(a, b) __gcd(a, b)
#define all(c) c.begin(), c.end()
#define vint vector<int>
#define vll vector<ll>
#define vpint vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define fr(it, a, b) \
    for (int it = (a); it < (b); it++)
#define tr(c, it) \
    for (auto it = c.begin(); it != c.end(); it++)
#define cpresent(c, e) (find(all(c), e) != c.end())
#define present(c, e) (c.find(e) != c.end())
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef unsigned long long lu;
const ll mod = 1e9 + 7;
int32_t main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    cout << (x >= 30 ? "Yes" : "No") << "\n";
    return 0;
}