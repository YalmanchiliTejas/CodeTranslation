#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    rep(b, 1, N+1){
        ll num = max(0LL, (b-1) - K + 1) * (ll)(N/b);
        //cerr << b << " " << num << " ";
        if(N % b != 0){
            ll rem = N - (ll)(N/b) * b;
            if(K == 0) num += max(0LL, rem - K);
            else num += max(0LL, rem - K + 1);
        }
        //cerr << num << endl;
        ans += num;
    }
    cout << ans << endl;
    return 0;
}