#include<bits/stdc++.h>
using namespace std;
typedef  long long  ll;
ll inf=LLONG_MAX,mod=1000000007,BS,k;

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
        #endif
        ll n;cin>>n;
        ll arr[n],suf[n];
        for(ll i=0;i<n;i++)cin>>arr[i];
        suf[n-1]=arr[n-1];
        for(ll i=n-2;i>=0;i--)
        suf[i]=(arr[i]+suf[i+1])%mod;
        ll sum=0;
        // sum=suf[n-1];
        for(ll i=n-2;i>=0;i--){
            sum=(sum+(arr[i]*(suf[i+1]))%mod)%mod;
        }
        cout<<sum;

}
