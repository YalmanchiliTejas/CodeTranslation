#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N,K;
    cin>>N>>K;
    ll ans=0ll;
    for (int i = K+1; i <= N; ++i) {
        int syo = N / i, amari = N % i;
        ans += (ll) syo * (i - K);
        if(K==0)ans+=(ll)max(amari,0);
        else ans += (ll) max(amari - K +1, 0);
    }

    cout<<ans<<endl;

    return 0;
}