#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N;
    cin >> N;

    vector<ll> a(N);
    rep(i,N) cin >> a[i];

    sort(a.begin(),a.end(), greater<ll>());
    int n = N / 2;
    if(N % 2 == 0){
        ll ans = 0;
        for(int i = 0; i < n; i++) ans += 2 * a[i];
        for(int i = n; i < N; i++) ans -= 2 * a[i];
        ans -= a[n-1];
        ans += a[n];
        cout << ans << endl;
    } else {
        int n = N / 2;
        ll sum1 = 0;
        for(int i = 0; i < n - 1; i++) sum1 += 2 * a[i];
        for(int i = n + 1; i < N; i++) sum1 -= 2 * a[i];
        sum1 += a[n] + a[n-1];

        ll sum2 = 0;
        for(int i = 0; i < n; i++) sum2 += 2 * a[i];
        for(int i = n + 2; i < N; i++) sum2 -= 2 * a[i];
        sum2 -= a[n] + a[n+1];
        cout << max(sum1,sum2) << endl;
    }
}

