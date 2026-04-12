#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define w(t) int t;cin>>t; while(t--)
using namespace std;



int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n; i++) cin>>arr[i];
    ll dp0[n], dp1[n];
    dp0[0] = 0;
    dp1[0] = 0;
    dp0[1] = arr[0];
    dp1[1] = arr[1];
    for(ll i=2; i<n; i++){
        if(i%2==0){
            dp0[i] = max(dp1[i-1], dp0[i-1]);
            dp1[i] = max(dp1[i-2], dp0[i-2]) + arr[i];
        }
        else{
            dp1[i] = dp0[i-1] + arr[i];
            dp0[i] = dp0[i-2] + arr[i-1];
        }
        // dp0[i] = max(dp0[i-1], dp1[i-1]);
        // if(i-2>=0){
        //     dp1[i] = max(dp0[i-2], dp1[i-2]) + arr[i];
        // }
        // else dp1[i] = arr[i];
    }
    cout<<max(dp1[n-1], dp0[n-1]);
}