#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

// low以上high以下のbaseの倍数の数
ll baisu(ll base, ll low, ll high){
    ll bt = (low + base - 1) / base;
    ll up = high / base;
    return up - bt + 1;
}

int main(){
    ll n, k;
    cin >> n >> k;
    if(k == 0) {
        cout << n * n << endl;
        return 0;
    }
    ll ans = 0;
    rep(b, 1, n+1) {
        if(b <= k) continue;
        auto uni = baisu(b, 1, n);
        ans += uni * (b - k);
        ll rem = n - uni * b;
        ans += max(0LL, rem - k + 1);
    }
    cout << ans << endl;
    return 0;
}