#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll=long long;
using P = pair<int,int>;
int main(){
    ll N;
    ll MOD = 1000000007;
    cin >> N;
    ll A[N];
    ll sum =0;
    for(ll i=0;i<N;i++){
        cin >> A[i];
        sum=(sum+A[i])%MOD;
    }
    ll ans =0;
    for(ll i=0;i<N-1;i++){
        sum=(sum-A[i]+MOD)%MOD;
        ll a = (A[i]*sum)%MOD;
        ans=(ans+a)%MOD;
    }
    cout << ans << endl;
}
