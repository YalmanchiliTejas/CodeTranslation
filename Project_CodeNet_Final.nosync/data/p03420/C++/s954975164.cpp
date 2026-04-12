#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll ans = 0;
    ll N, K; cin >> N >> K;
    if(K == 0){
        cout << N*N << endl;
        return 0;
    }
    for(ll b = K+1; b <= N; b++){
        //a % b >= K
        //a = K, K+b, ...
        //K + mb <= Nなるm>=0の個数
        //m <= (N-K)/b
        //あまりはK,...,b-1まであり得る -> (b-1) - K + 1個
        //N % b < Kならはみ出てない
        ll nums = (b-1)-K + 1;
        ll over = 0;
        if(N % b >= K) over = nums - (N%b - K + 1);
        ans += nums*((N-K)/b+1)-over;
    }
    cout << ans << endl;
    return 0;
}