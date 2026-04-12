#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll a[n];
    ll sum = 0;
    for(ll i = 0;i<n;i++){
        cin>>a[i];
        sum += a[i];
    }
    ll ans = 0;
    for(ll i= 0;i<n;i++){
        sum = sum - a[i];
        ans = ans%M + ( (sum%M)*(a[i]%M))%M;
    }
    cout<<ans%M<<endl;
}
