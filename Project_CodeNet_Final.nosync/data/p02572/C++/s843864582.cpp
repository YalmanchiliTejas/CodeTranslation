#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

void boost(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    boost();
    ll n;
    cin >> n;
    ll arr[n],i;
    for(i=0;i<n;i++)
    cin >> arr[i];
    ll sum[n];
    sum[0]=arr[0];
    for(i=1;i<n;i++)
    sum[i]=arr[i]+sum[i-1];
    
    ll ans=0;
    for(i=1;i<n;i++){
        sum[i-1]%=mod;
        arr[i]%=mod;
        ans+=arr[i]*sum[i-1];
        ans=ans%mod;
    }
    
    cout << ans << endl;
}