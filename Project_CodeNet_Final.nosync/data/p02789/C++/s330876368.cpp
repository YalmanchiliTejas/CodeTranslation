//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define setbits(x) __builtin_popcount(x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;
typedef vector<int> vi;
#define m1 make_pair
#define in insert
#define pb push_back
#define IOS                           \
    std::ios::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define endl "\n"
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

inline ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
inline ll power(ll a, ll n, ll m)
{
    if (n == 0)
        return 1;
    ll p = power(a, n / 2, m);
    p = (p * p) % m;
    if (n % 2)
        return (p * a) % m;
    else
        return p;
}
const ll MOD = 1000000007;
const int N = int(3e5) + 999;
#define int long long int

int32_t main(){
    IOS;
    int n,m;
    cin>>n>>m;
    if(n==m)
    	cout<<"Yes\n";
    else
    	cout<<"No\n";

    return 0;
}