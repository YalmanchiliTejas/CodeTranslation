   #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ff first
    #define ss second
    #define pb push_back
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define MOD 1000000007
    #define pll pair<ll,ll>
constexpr ll INF = 1999999999999999997; 
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    int main() {
        fastio;

        int n;
        cin>>n;
        ll a[n];
        ll pre[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i!=0)
                pre[i]=pre[i-1]+a[i];
            else
                pre[i]=a[i];
            
        }
        ll ans=0;
        for(int i=0;i<n-1;i++)
        { 
             ans=ans%MOD+((pre[n-1]-pre[i])%MOD*(a[i]%MOD))%MOD;
             ans%=MOD;
        } 
        cout<<ans<<endl;
    }