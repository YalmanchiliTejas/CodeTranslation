


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second

using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9 + 7;
// const int mod=998244353;
//const int mod=1e9+9;
//const int INF=4e18+10;
const int INF = 4e18 + 10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define read(n) \
int n;      \
cin >> n;
#define readv(x, n)   \
vector<int> x(n); \
for (auto &i : x) \
    cin >> i;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

template <typename T1, typename T2>
void set_min(T1 &a, T2 b)
{
    a = min(a, (T1)b);
}

int multiply(int a, int b, int in_mod) { return (a * b) % in_mod; }
int mult_identity(int a) { return 1; }


auto power(auto a, int b, int in_mod)
{
    auto prod = mult_identity(a);
    auto mult = a % in_mod;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod - 2, in_mod);
}


const int MAXN = 1e5+100;
int parent[MAXN];
void build()
{
    for(int i=0;i<MAXN;i++)
        parent[i] = i;
}

int find_set(int u)
{
    if( u== parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
}
void merge(int u, int v)
{
    u= find_set(u);
    v= find_set(v);
    if(u!=v)
    {
        if(rand()%2)
            swap(u,v);
        parent[v] = u;
    }

}

void solve()
{
    build();
    int n;
    cin>>n;
    vector<pair<pair<int, int>, int>> a;
    for(int i= 0;i<n;i++)
    {
        int x, y;
        cin>>x>>y;
        a.pb({{x,y}, i});
    }


    sort(all(a));

    for(int i= 0;i<n-1;i++)
    {
        if(a[i].fi.fi ==a[i+1].fi.fi)
            merge(a[i].se, a[i+1].se);
    }

    sort(all(a), [](auto &left, auto &right){
        return left.fi.se < right.fi.se;
    });



    for(int i= 0;i<n-1;i++)
    {
        if(a[i].fi.se ==a[i+1].fi.se)
            merge(a[i].se, a[i+1].se);
    }
    vector<pair<int,pair<int, int>>> club;


    for(int i= 0;i<n-1;i++)
    {
        if(find_set(a[i].se) !=find_set(a[i+1].se))
            club.pb({ abs(a[i].fi.se - a[i+1].fi.se), {find_set(a[i].se), find_set(a[i+1].se)}});
    }
    sort(all(a));
    for(int i= 0;i<n-1;i++)
    {
        if(find_set(a[i].se) !=find_set(a[i+1].se))
            club.pb({ abs(a[i].fi.fi - a[i+1].fi.fi), {find_set(a[i].se), find_set(a[i+1].se)}});
    }

    int ans = 0;
    sort(all(club));

    for(auto i:club)
    {
        if(find_set(i.se.fi)!=find_set(i.se.se))
            merge(i.se.fi, i.se.se), ans+=i.fi;
    }
    cout<<ans<<endl;


}




signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
#ifndef ONLINE_JUDGE
    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    }
#endif
    auto clk = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // -------------------------------------Code starts here---------------------------------------------------------------------

    int t = 1;
    // cin >> t;

    for (int test = 1; test <= t; test++)
    {
        // cout<<"Case #"<<test<<":\n";
        //cout<<"Trip #"<<test<<": ";
        // cout<<endl;
        solve();
        // solveB();

        // cout<<endl;
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;
    // cerr << fixed << setprecision(6) << "Time: " << ((long double)clk) / CLOCKS_PER_SEC << "\n";
    return 0;
}
