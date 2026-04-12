#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int limit = pow(10, 9) + 7;
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<ll> sum(N+1, 0);
    for(int i = 1; i < N+1; i++){
        sum[i] = sum[i-1] + a[i-1];
    }

    ll ans = 0;
    rep(i, N-1){
        ans = (ans + (((sum[N] - sum[i+1]) % limit) * a[i]) % limit) % limit;
    }
    cout << ans << endl;
    return 0;
}