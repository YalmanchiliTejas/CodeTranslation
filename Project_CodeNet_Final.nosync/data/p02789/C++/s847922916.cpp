    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define pb push_back
    #define mp make_pair
    #define mod 1e9+7
    #define sz 100000
    #define f(i,n) for(ll i=0;i<n;i++)
    #define fab(i,a,b) for(ll i=a;i<b;i++)
    #define fr(i,n) for(ll i=n-1;i>=0;i--)
    #define fba(i,b,a) for(ll i=b-1;i>=a;i--)
    #define tc(t) ll t;cin>>t;while(t--)
     
    ll pw(ll x,unsigned ll y) 
    { 
        if (y==0) 
            return 1; 
        else if (y%2==0) 
            return pw(x,y/2)*pw(x,y/2); 
        else
            return x*pw(x,y/2)*pw(x,y/2);
    }
     
    int main() 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        ll a,b;
        cin>>a>>b;
        if(a==b) cout<<"Yes";
        else cout<<"No";
        return 0;
    }