#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"
const int M = 1e5;
int pos[M];
int seq[1 + M];
ll sumSeq[1 + M];

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    ll n; int x, m;
    cin >> n >> x >> m;
    seq[1] = x;
    int index = 1;
    sumSeq[1] = x;
    int nxt = (1ll * x * x) % m;
    while (index < n && not pos[nxt]) {
        seq[++index] = nxt;
        sumSeq[index] = sumSeq[index - 1] + nxt;
        pos[nxt] = index;
        nxt = (1ll * nxt * nxt) % m;
    }
    if (index == n) {
        cout << sumSeq[n] << "\n";
        return 0;
    }
    int period = index - pos[nxt] + 1;
    int start = pos[nxt];
    if (start > n) {
        cout << sumSeq[n] << "\n";
    }
    else {
        ll ans = 0;
        ans += sumSeq[start - 1];
        n -= start - 1;
        ans += (sumSeq[start + period - 1] - sumSeq[start - 1]) * (n / period);
        ans += (sumSeq[start + n % period - 1] - sumSeq[start - 1]);
        cout << ans << "\n";
    }
    return 0;
}
