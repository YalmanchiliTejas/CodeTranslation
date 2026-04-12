#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e9
#define PI 3.141592653589793238
#define N 1000000010
#define mod 1000000007
typedef long long ll;

int main() {
    ll n,ans=0, sum=0; cin>>n;
    ll a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
    }

    for(int i=0; i<n-1; i++){
        sum -= a[i];
        ans += (a[i]*(sum%mod))%mod;
        ans %= mod;
    }
    cout<<ans<<endl;


    return 0;
}