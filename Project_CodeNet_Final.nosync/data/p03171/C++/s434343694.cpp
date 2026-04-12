
    #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;
    int main()
    {
        std::ios::sync_with_stdio(false);
        int T=1;
        //cin>>T;
        // cin.ignore(); must be there when using getline(cin, s)
        while(T--)
        {
            ll n;
            cin>>n;
            ll a[n];
            for(ll i=0;i<n;i++)
                cin>>a[i];
            ll dp[n+1][n+1];
            for(ll l=n-1;l>=0;l--)
            {
                for(ll r=l;r<n;r++)
                {
                    if(l==r)
                        dp[l][r]=a[l];
                    else
                        dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
                }
            }
            cout<<dp[0][n-1];
        }
        return 0;
    }
