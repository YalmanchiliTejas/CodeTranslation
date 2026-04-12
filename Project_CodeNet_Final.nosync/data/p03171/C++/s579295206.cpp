
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")

    /*
    ||||||||||||||||||||||||||||||||||||||||||||||||
       |      |||         |      ||||    ||||  |   |
      | |     |   |      | |     |   |  |      |   |
     |   |    |    |    |   |    |   |  |      |   |
    |||||||   |    |   |||||||   |||     |||   |||||
    |     |   |   |    |     |   | |        |  |   |
    |     |   |||      |     |   |  ||  ||||   |   |
    ||||||||||||||||||||||||||||||||||||||||||||||||

    */
    using namespace std;
    //#include "testlib.h"
    #define ff first
    #define ss second
    #define mp make_pair
    #define all(v) v.begin(),v.end()
    #define int long long
    #define ll long long
    #define M 1000000007
    #define inputarr(a,n) for(int i=0;i<n;++i) cin>>a[i]
    #define GCD(m,n) __gcd(m,n)
    #define LCM(m,n) m*(n/GCD(m,n))
    #define mii  map<ll ,ll >
    #define msi  map<string,ll >
    #define mis  map<ll int, string>
    #define rep(a,b)    for(ll i=a;i<b;i++)
    #define rep0(n)    for(ll i=0;i<n;i++)
    #define repi(i,a,b) for(ll i=a;i<b;i++)
    #define pb push_back
    #define vi vector<ll>
    #define mp make_pair
    #define vs vector<string>
    #define ppb pop_back
    #define endl '\n'
    #define asdf ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    #define r0 return 0;
    #define FORD(i, a, b) for (int i = (int) (a); i >= (int) (b); --i)
    #define FORE(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
    #define inputoutput freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #define input freopen("input.txt", "r", stdin);
    #define Set(a, s) 4(a, s, sizeof (a))
    #define FOR repi
    #define pii pair<int,int>
    #define REVERSE(v) reverse(ALL(v))
    #define display(x) trav(a,x) cout<<a<<" ";cout<<endl
    #define debug cerr<<"bhau"<<endl
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        std::cerr << name << " : " << arg1 << endl;
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
 
    //#define float long double
    ll max(ll a, ll b) { return (a > b)? a : b;}
    int min(int a, int b) { return (a < b)? a : b;}
    const int maxn=3001;
    int dp[maxn][maxn];
     int solve()
     {  
        int n;cin>>n;
        vi a(n);
        inputarr(a,n);
        for(int l=n-1;l>=0;l--){
            for(int r=0;r<n;r++){
                if(l==r){
                    dp[l][r]=a[l];
                }
                else{
                    if(r)
                    dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp
                        [l][r-1]);
                    else dp[l][r]=a[l]-dp[l+1][r];
                }
            }
        }
        cout<<dp[0][n-1];
        r0   
     }
    signed main()
    {   
        asdf
        // #ifndef ONLINE_JUDGE
        // inputoutput
        // #endif
        int t=1;
        //cin>>t;
        while(t--)
        {
            solve();
        }     
        
}