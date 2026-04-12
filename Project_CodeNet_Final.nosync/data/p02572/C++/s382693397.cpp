#include<bits/stdc++.h>
using namespace std;
#define Nitroboost  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int 
const int mod=1e9+7;
const int N=1e5+5;


int main()
    {
        Nitroboost;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif

        int n;
        cin>>n;
        ll a[n];
        ll total=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans=(ans+a[i]*total*1ll%mod)%mod;
            total=(total+a[i])%mod;
        }

        
       
        cout<<ans;

    }
