#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N,K; cin >> N >> K;
    if (!K){cout << N*N << '\n'; return 0;}
    ll ans=0;
    for (ll i=K+1;i<=N;++i){
        ans+=N/i*(i-K)+max(N%i-K+1,0LL);
    }
    cout << ans << '\n';
}