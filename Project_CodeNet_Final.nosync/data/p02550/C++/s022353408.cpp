//#define _GLIBCXX_DEBUG
//#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")


#define pb push_back 
#define f first
#define s second
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define all(v) v.begin(), v.end()

typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

template <class T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 1e9;
//const ll INF = 1e18;
const ll mod = 1000000007;
// const ll mod = 998244353;

void solve(int tc){
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = 0;
    ll prev = x;
    map<ll, int> mp; 
    mp[prev] = 1;
    map<ll, ll> sums;
    ll i;
    for(i = 1; i <= n; i++){
        sums[i] = sums[i-1] + prev;
        prev = (prev*prev)%m;
        if(mp[prev])
            break;
        else
            mp[prev] = i+1;
    }

    ll j = mp[prev];
    ll temp = sums[j-1];
    ll temp2 = sums[i]-temp;
    temp2 *= (n-j+1)/(i-j+1);
    temp += temp2;

    ll taken = j-1 + (i-j+1)*((n-j+1)/(i-j+1));
    taken = n - taken;

    temp += sums[j-1+taken] - sums[j-1];

    cout << temp << "\n";
}

int main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    int tc = 1;
    //cin >> tc;
    for (int t = 0; t < tc; t++) solve(t);

    return 0;
}