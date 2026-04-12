#pragma GCC optimize("O3")

#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/rope"

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) for(int i = 0; i < (a); ++i)
#define pb push_back
#define mp make_pair
#define sz(x) (int)x.size()
#define f first
#define s second

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const 
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int n;
vector<ll> a;
multiset<ll> cur;
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.assign(n, 0);
    F0R(i, n) cin >> a[i];
    cur.insert(a[n - 1]);
    for(int i = n - 2; i >= 0; --i)
    {
        auto itx = cur.upper_bound(a[i]);
        if(itx == cur.end()) cur.insert(a[i]);
        else
        {
            cur.erase(itx);
            cur.insert(a[i]);
        }
    }
    cout << sz(cur);
    return 0;
}