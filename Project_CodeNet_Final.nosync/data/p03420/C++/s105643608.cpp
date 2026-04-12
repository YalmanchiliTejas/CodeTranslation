#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    rep(b, K+1, N+1){
        ll kiri = (N+1)/b;
        ans += (b-K)*kiri;
        ll rem = N - K - (kiri)*b;
        ans += max(0LL, rem+1LL);
    }

    if(K==0) ans = N*N;
    cout << ans << endl;
    return 0;
}