#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N,K; cin >> N >> K;
    ll ans = 0;
    if(K == 0){
        cout << N*N << endl;
        return 0;
    }
    for(int b = K+1; b <= N; b++){
        //K+mb <= Nとなる最大のm: m <= (N-K)/b
        int mul = b-K;
        ans += ((N-K)/b + 1)*mul;
        //あまりがKからb-1まで考える
        if(N % b >= K){
            ll rem = N % b;
            //remがK+1だったら,rem+1,...,b-1を余分に一回ずつ数えている
            ans -= b-rem-1;
        }
    }
    cout << ans << endl;
    return 0;
}