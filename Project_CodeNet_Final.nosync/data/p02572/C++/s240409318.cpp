#include<bits/stdc++.h>

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(int i=a; i<= b; ++i)
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define Ld long double

using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int main(){
    optimize();
    ll n;
    cin>>n;
    vector<ll> arr(n);
    FOR(i,0,n-1) cin>>arr[i];

    ll sum = 0;
    ll prefixSumArray[n];

    prefixSumArray[0] = 0;
    prefixSumArray[1] = arr[0];
    FOR(i,2,n-1) prefixSumArray[i] = (prefixSumArray[i-1]+arr[i-1])%mod;

    FOR(i,0,n-1)
    {
        sum += prefixSumArray[i]*arr[i];
        sum %= mod;
    }
    cout<<sum<<endl;
    return 0;
}
