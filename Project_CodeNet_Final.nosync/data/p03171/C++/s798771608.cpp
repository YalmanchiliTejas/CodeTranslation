#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <map>
#include <unordered_map>
#include <climits>
using namespace std;
const int INF = 1e9;
#define ll long long
#define int ll
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define testcase \
    int t;       \
    cin >> t;    \
    while (t--)
#define pb push_back
#define endl "\n"
#define deb1(x) cout << #x << ": " << x << endl
#define deb2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl
#define deb3(x, y, z) cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define deb4(x, y, z, w) cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << " | " << #w << ": " << w << endl
#define deb5(a, b, c, d, e) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(a) int((a).size())
#define pii pair<int, int>
#define fi first
#define se second
#define ld long double
#define vii vector<int>
#define all(v) v.begin(), v.end()
#define prec(n) fixed << setprecision(n)
const int MOD = (int)1e9 + 7;
const int MOD2 = 1007681537;
const ll LINF = (ll)1e18;
const ld PI = acos((ld)-1);
const ld EPS = 1e-12;
inline ll gcd(ll a, ll b)
{
    ll r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
inline ll fpow(ll n, ll k, int p = MOD)
{
    ll r = 1;
    for (; k; k >>= 1)
    {
        if (k & 1)
            r = r * n % p;
        n = n * n % p;
    }
    return r;
}
template <class T>
inline int chkmin(T &a, const T &val) { return val < a ? a = val, 1 : 0; }
template <class T>
inline int chkmax(T &a, const T &val) { return a < val ? a = val, 1 : 0; }
inline void addmod(int &a, int val, int p = MOD)
{
    if ((a = (a + val)) >= p)
        a -= p;
}
inline void submod(int &a, int val, int p = MOD)
{
    if ((a = (a - val)) < 0)
        a += p;
}
inline int mult(int a, int b, int p = MOD) { return (ll)a * b % p; }
inline int inv(int a, int p = MOD) { return fpow(a, p - 2, p); }

template <class T>
inline void get_arr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
template <class T>
inline void print_arr(T arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

const int nmax=3005;
int dp[nmax][nmax];

int32_t main()
{
    int n;
    cin>>n;
    int arr[n];
    get_arr(arr,n);
    for(int L=n-1;L>=0;L--)
    {
        for(int R=L;R<n;R++)
        {
            if(L==R)
            {
                dp[L][R]=arr[L];
            }
            else
            {
                dp[L][R]=max(arr[L]-dp[L+1][R],arr[R]-dp[L][R-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}
