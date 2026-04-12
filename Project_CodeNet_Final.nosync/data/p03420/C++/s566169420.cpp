#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    rep(i,1,N+1){
        if(i <= K)continue;
        ll k = N / i;
        ans += (i - K) * k;
        //cout << i << " " << k << " " << N - i * k - K << endl;
        ans += max(0LL, N - i * k - max(1LL,K) + 1);
    }
    cout << ans << endl;
}