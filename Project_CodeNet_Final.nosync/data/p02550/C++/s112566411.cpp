#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
#define pb push_back
#define vec vector<int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define foo(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define deb(x) cout << #x << " --> " << x << endl;
#define deb1a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
        cout << it << " ";        \
    cout << endl;
#define deb2a(v)                  \
    cout << #v << "--->" << endl; \
    for (auto it : v)             \
    {                             \
        for (auto it1 : it)       \
        {                         \
            cout << it1 << " ";   \
        }                         \
        cout << endl;             \
    }
#define deb3a(v)                               \
    cout << #v << "-->" << endl;               \
    for (auto it : v)                          \
    {                                          \
        cout << it.fi << " " << it.se << endl; \
    }
//#define mod 1000000007
#define mod 998244353
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int mI(int a, int m)
{
    return power(a, m - 2, m);
}
vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
#define double long double


void solve()
{
    int n, x, m;
    cin >> n >> x >> m;
    vec v1(100005,0),v3(100005,0);
    v1[0] = 0;
    map<int, int> mm;
    v1[1] = x;
    v3[1] = x;
    int poss = -1, pose = -1;
    int ans = 0;
    for (int i = 2; i < 100005;i++){
        v1[i] = (v1[i - 1] * v1[i - 1]) % m;
        v3[i] = v1[i] + v3[i - 1];
            //deb(v1[i]);
        if(mm[v1[i]]!=0){
            poss = mm[v1[i]];
            pose = i;
            break;
        }
        else{
            mm[v1[i]] = i;
        }
    }
    vec v2;
    v2.pb(0);
    foo(i,poss+1,pose+1){
        v2.pb(v1[i]);
    }
    //deb1a(v2);
    foo(i,1,v2.size()){
        v2[i] += v2[i - 1];
    }
    int si = v2.size() - 1;
    //db2(poss, pose);
    //deb(v3[poss]);
    if(n<=poss){
        cout << v3[n];

    }
    else{
        int ans = 0;
        int left = n - poss;
        int aa = left / si, bb = left % si;
        ans = v3[poss] + aa * v2.back() + v2[bb];
        cout << ans;
    }
    

}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(time(0));

    // FILE *fin = freopen("ip.txt","r",stdin);
    // FILE *fout = freopen("op.txt","w",stdout);
    int t = 1, nn = 1;
    //cin >> t;
    while (t--)
    {
        // cout << "Case #" << nn << ":"
        //      << " ";
        // nn++;

        solve();
    }
}