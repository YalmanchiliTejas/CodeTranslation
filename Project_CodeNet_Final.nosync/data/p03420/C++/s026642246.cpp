#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void main_()
{
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for (ll b = 1; b <= N; b++) {
        ans += (N / b) * max(0LL, b - K);
        ans += max(0LL, N % b - K + 1);
        if (K == 0) {
            // K==0の時はa=0が余り0として入るのでその分を除外する
            ans--;
        }
    }
    cout << ans << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
