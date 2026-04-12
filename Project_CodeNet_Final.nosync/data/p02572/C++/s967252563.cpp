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
    ll prefixSum = 0;

    FOR(i,0,n-1)
    {
        sum += prefixSum*arr[i];
        prefixSum += arr[i];
        prefixSum %= mod;
        sum %= mod;
    }
    cout<<sum<<endl;
    return 0;
}
