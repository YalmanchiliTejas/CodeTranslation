#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(A.begin(), A.end(), greater<ll>());
    if(N % 2 == 0){
        ll ans = 0;
        rep(i, 0, N/2-1) ans += A[i] * 2;
        ans += A[N/2 - 1] - A[N/2];
        rep(i, N/2+1, N) ans -= 2 * A[i];
        cout << ans << endl;
    }else{
        ll ans1 = 0, ans2 = 0;
        rep(i, 0, N/2-1) ans1 += A[i] * 2;
        ans1 += A[N/2 - 1] + A[N/2];
        rep(i, N/2+1, N) ans1 -= A[i] * 2;
        rep(i, 0, N/2) ans2 += A[i] * 2;
        ans2 -= A[N/2 + 1] + A[N/2];
        rep(i, N/2+2, N) ans2 -= A[i] * 2;
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}