#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;

    if(K == 0){
        cout << N * N << endl;
        return 0;
    }

    ll ans = 0;
    rep(b, 1, N+1){
        ll bb = N/b;
        //cerr << b << " " << bb << endl;
        ans += max(b - K, 0LL) * bb;
        ans += max(N - b * bb - K + 1, 0LL);
    }
    cout << ans << endl;
    return 0;
}