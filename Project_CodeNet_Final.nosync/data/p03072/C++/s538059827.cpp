    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp> // Common file
    #include <ext/pb_ds/tree_policy.hpp>
    #include <functional> // for less

    using namespace std;
    #define md 1000000007
    #define itn int
    #define pb push_back
    #define mp make_pair
    // #define ull unsigned long long int
    #define ll long long 
    // #define int ll
    #define ppi pair<int, int>
    #define ppl pair<ll, ll>
    #define vi vector<int>
    #define all(x) x.begin(), x.end()
    #define ff first
    #define lb lower_bound
    #define ub upper_bound
    #define ss second
    #define inf 1e9
    #define enld '\n'
    #define cuot cout
    #define trace1(x) cerr << #x << ": " << x << endl
    #define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
    #define trace3(x, y, z)                                                        \
      cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": "    \
           << z << endl
    #define trace4(a, b, c, d)                                                     \
      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
           << c << " | " << #d << ": " << d << endl
    #define trace5(a, b, c, d, e)                                                  \
      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
           << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
    #define trace6(a, b, c, d, e, f)                                               \
      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": "   \
           << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | "   \
           << #f << ": " << f << endl
    #define trace(v)                                                               \
      for (auto it = v.begin(); it != v.end(); it++)                               \
        cerr << *it << " ";                                                        \
      cerr << endl;
    #define linf 1e18
    #define reset(x) memset(x, 0, sizeof(x))
    #define rep(i, a, b) for (int i = a; i < b; i++)

    using namespace __gnu_pbds;

    typedef tree<int, null_type, less<int>, rb_tree_tag,
                 tree_order_statistics_node_update>
        oset;

    void fastio() {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
    }
    
   
    void solve()
    {  
        int n;cin>>n;
        int mx=0;
        int ans=0;
        rep(i,0,n){
            int t;cin>>t;
            if(t>=mx)ans++;
            mx=max(mx,t);
        }
        cout<<ans<<endl;
    }


    signed main() {
      fastio();
      int t;
      t = 1;
      // cin >> t;
      for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
      }
      return 0;
    }
