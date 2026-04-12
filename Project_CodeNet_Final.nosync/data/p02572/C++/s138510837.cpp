        #include <bits/stdc++.h>
        #define ll  long long int
        #define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
        #define mod 1000000007
        using namespace std;
    
        int main()
            {fast;
            ll t =1;
            //cin>>t;

        while(t--){
            ll n;
            cin>>n;

            ll arr[n];
            ll sum=0;
            for(int i=0; i<n;i++)
            cin>>arr[i], sum+=arr[i];
            ll ans=0;
            sum%=mod;
            for(int i=0; i<n-1;i++){
                sum-=arr[i];
                sum=(sum+mod)%mod;
                ans+= (sum*arr[i])%mod;
                ans%=mod;
            }
            cout<<(ans+mod)%mod;
        }
                return 0;
        }