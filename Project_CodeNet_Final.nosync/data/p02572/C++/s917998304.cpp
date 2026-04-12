#include<bits/stdc++.h>
#define ll          long long int
#define pb          push_back
#define mpp         make_pair
#define vll         vector<ll>
#define mll         unordered_map<ll,ll>
#define endl        "\n"
#define debug(x)    cout<< #x <<"="<<x<<"\n"
#define fo(i,a,x)   for(ll i=a;i<x;++i)
#define fastio      ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

ll M = 1000000007;

void solve()
{
    ll n; cin>>n;
    vll arr(n);
    fo(i,0,n)
    {
        cin>>arr[i];
    }   
    vll suff(n);
    suff[n-1] = 0;  
    for(int i=n-2;i>=0;i--)
    {
        suff[i] = suff[i+1]+arr[i+1];
    }
    ll ans = 0;
    fo(i,0,n)
    {
        ans = ans%M + (arr[i]%M * (suff[i]%M)%M)%M;
    }
    cout<<ans<<endl;
}

int main()
{
    fastio;
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    ll t=1; 
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}