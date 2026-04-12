/*
    Mbak Sana Dong
    Mbak Chaeyoung Dong
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9+7;
ll arr[200200];
ll power(ll a, ll b)
{
    ll ret = 1;
    while(b>0) {
        if(b%2==1) ret = (ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}
int main()
{
    int n,i,j,k,x,y,ans,curr,temp,m;
    int tc;
    ll sum = 0;
    cin >> n;
    for(i=1;i<=n;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll chaeng = 0;
    for(i=1;i<=n;i++) {
        ll sisa = sum - arr[i];
        sisa %= mod;
        chaeng += sisa*arr[i];
        chaeng %= mod;
    }
    chaeng = chaeng * power(2, mod - 2);
    chaeng %= mod;
    cout<<chaeng<<endl;
    return 0;
}
