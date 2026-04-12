#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define ll long long
#define int ll
#define eps 1e-7
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using pii = pair<int, int>;
using cd = int;
const bool debug = 0;
const int mod = 1000000007;
const int rev2 = 5e8+4;
int a, b;
int32_t main()
{
  	usecppio
    int n; cin >> n;
    for (int i = 0; i<n; i++)
    {
        int x; cin >> x;
        a += x;
        b += x*x;
        a %= mod;
        b %= mod;
    }
    cout << ((((a*a)-b+mod)%mod)*rev2)%mod << '\n';
}