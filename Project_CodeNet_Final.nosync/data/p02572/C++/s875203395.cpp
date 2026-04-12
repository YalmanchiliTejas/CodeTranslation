#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000030;
int main() {
    int n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans=0;
    ll sum=0;
    for(int i=n-2;i>=0;i--){
        sum+=arr[i+1];
        ans=(ans%MOD+(sum*arr[i])%MOD)%MOD;
        sum%=MOD;
    }
    cout<<ans%MOD<<endl;
    return 0;
}