#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = (int)(s); i < (int)(n); i++)
const ll mod = ll(1e9) + 7;
const int INF = int(1e9);
int main()
{
    int N;
    cin >> N;
    vector<int> H(N);
    rep(i, N) cin >> H[i];
    int ans = 0;
    int max_h = 0;
    rep(i, N)
    {
        if (H[i] >= max_h)
        {
            ans++;
            max_h = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}
