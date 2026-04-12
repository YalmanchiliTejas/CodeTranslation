#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define db(x) (cerr << #x << ": " << (x) << '\n')
#define cps CLOCKS_PER_SEC
#define tests(t) int t; cin >> t; while(t--)
#define iceil(n, x) (((n) + (x) - 1) / (x))
#define eb emplace_back
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define sz size()
#define all(v) (v).begin(), (v).end()
#define uni(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define fi first
#define se second
#define bitcount(x) __builtin_popcount(x)
#define bit(x) (1LL << x)
#define PI acos(-1.0)
#define EPS 1e-9

#define mod 1000000007
#define maxn 2005

using namespace std;

using namespace __gnu_pbds;
template<class key, class cmp = std::less<key>>
using ordered_set = tree<key, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
///All indexing is 0-based
///methods: find_by_order(k); & order_of_key(k);
///To make it an ordered_multiset, use pairs of (value, time_of_insertion)
///to distinguish values which are similar

typedef long long ll;
typedef double ld;
typedef pair<ll, ll> par;



int main()
{
    #ifdef acm
    freopen("a.in","r",stdin);
    #endif // acm
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    if(N == M)
        cout << "Yes\n";
    else
        cout << "No\n";







}

