#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, K; cin >> N >> K;
    ll ans=0;
    for(ll i=K+1; i<=N; i++){
        ans +=(N/i * (i-K) );
        ans += max(0LL, N%i-K+1LL );
        if(K==0) ans--;
//        cout << (N/i * (i-K) )  + max(0LL, N%i-K ) << endl;
    }
    cout << ans << endl;
}