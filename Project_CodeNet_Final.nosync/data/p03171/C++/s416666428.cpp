    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long int
    #define f(i,n) for(ll i=0;i<n;i++)
    #define fz for(ll j=i+1;j<n;j++)
    #define f2(i,n) for(ll i=1;i<=n;i++)
    #define endl "\n"
    #define vll vector <ll>
    #define sz(a) (ll)a.size()
    #define mod 1000000007
    #define pb push_back
    #define inf 1e13+5

    ll gcd(ll a, ll b){if(b==0)return a;return gcd(b, a%b);}
    ll lcm(ll a, ll b){return a*b/gcd(a, b);}
    ll fexp(ll a, ll b){ll ans = 1;while(b){if(b&1) ans = ans*a%mod; b/=2;a=a*a%mod;}return ans;}
    ll inverse(ll a, ll p){return fexp(a, p-2);} 

    ll dp[3003][3003];
    ll game(ll *arr,ll l,ll r){
        if(l>r)return 0;
        if(l==r)return arr[l];
        if(dp[l][r]!=-(ll)1e18)return dp[l][r];
        return ( dp[l][r]=max(arr[l]-game(arr,l+1,r), arr[r]-game(arr,l,r-1)) );
    }
    
    void solve(){
      ll n;cin>>n;
      ll a[n];f(i,n)cin>>a[i];
      f(i,n){
          f(j,n)dp[i][j]=-(ll)1e18;
      }
      ll ans=game(a,0,n-1);
      cout<<ans<<endl;
                                                                                    

    }


    int main(){
        ios_base::sync_with_stdio(0) ;
        cin.tie(0) ; cout.tie(0) ;

       
        ll t;
        t=1;
        // cin>>t;
        while(t--){
            solve();
        }

       
        
        return 0;
    }