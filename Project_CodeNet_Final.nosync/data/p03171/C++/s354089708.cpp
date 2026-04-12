#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll nax=3005;
ll dp[nax][nax];
int main(){
    ll n;cin>>n;
    ll a[3005];
    for(ll i=0;i<n;i++)cin>>a[i];

  //  ll dp[3005][3005];

    for(ll L=n-1;L>=0;L--){
       for(ll R=L;R<n;R++){
            if(L==R){
                dp[L][R]=a[L];
            }
            else{
                dp[L][R]=max(a[L]-dp[L+1][R],a[R]-dp[L][R-1]);
            }
        }
    }
    //cout<<"sahil";
    cout<<dp[0][n-1];
}