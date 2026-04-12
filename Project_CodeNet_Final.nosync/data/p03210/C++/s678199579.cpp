#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstring>

#define ll long long
#define scani(x) scanf("%i", &x)
#define scanll(x) scanf("%I64d", &x)
#define scanfl(x) scanf("%f", &x)
#define scanch(x) scanf("%c", &x)
#define scans(x) scanf("%s", x);
#define printi(x) printf("%i", x);
#define printll(x) printf("%I64d", x);
#define printfl(x) printf("%f", x);
#define printch(x) printf("%c", x);
#define prints(x) printf("%s", x);
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define INFI (1 << 29)
#define INFL (1LL << 62)
#define sz(x) int(x.size())
#define fi first
#define se second
#define forn(i, n) for(ll i = 0; i < n; i++)
#define for1(i, n) for(ll i = 1; i <= n; i++)
#define ford(i, n) for(ll i = (n - 1); i >= 0; i--)
#define fori(i, n) for(ll i = n; i >= 1; i--)
#define fore(i, l, r) for(ll i = l; i <= r; i++)

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;

    cin >> n;

    cout << (((n == 7) || (n == 5) || (n == 3)) ? "YES" : "NO") << "\n";

    return 0;
}
