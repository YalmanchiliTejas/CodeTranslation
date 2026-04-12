#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define PI 2 * acos(0.0)
#define MAX 1000000
#define INF 1000000 
#define M 1000000007
using namespace std;
int main(){
    FAST
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
