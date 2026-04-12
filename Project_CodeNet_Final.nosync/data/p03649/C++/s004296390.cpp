#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];
    ll ans = 0;
    while(true){
        auto itr = max_element(a.begin(), a.end());
        if(*itr <= N-1) break;
        ll rem = *itr - (N - 1);
        ll red = (rem + N - 1)/N;
        *itr -= red * N;
        *itr -= red;
        ans += red;
        rep(i, 0, N) a[i] += red;
    }
    cout << ans << endl;
    return 0;
}