#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
typedef long long int ll;

constexpr ll mod=1e9+7;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> sum(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    for(int i=0;i<n;i++){
        sum[i+1]=sum[i]+a[i];
        sum[i+1]%=mod;
    }
    ll res=0;
    reverse(a.begin(), a.end());
    for(int i=0;i<n;i++){
        res+=a[i]*sum[n-i-1]%mod;
        res%=mod;
    }
    cout << res << endl;
}
