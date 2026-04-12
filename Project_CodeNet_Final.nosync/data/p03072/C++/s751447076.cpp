
#include <bits/stdc++.h>

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
    #define ff first
    #define ss second
    #define mp make_pair
    #define all(v) v.begin(),v.end()
    #define int long long
    #define ll long long
    #define M 1000000007

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
    //#define float long double
    ll max(ll a, ll b) { return (a > b)? a : b;}
    int min(int a, int b) { return (a < b)? a : b;}


     int solve()
     {
        int n;
        cin>>n;
        vi h(n);
        rep0(n) cin>>h[i];
        int ans=1,ma=h[0];
        rep(1,n){
            if(h[i]>=ma)
            {
                ma=h[i];
                ans++;
            }
        }
        cout<<ans;
     }
    signed main()
    {   
        
        int t=1;
        //cin>>t;
        while(t--)
        {
            solve();
        }     
        
}