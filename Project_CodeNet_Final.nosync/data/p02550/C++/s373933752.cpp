#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ull unsigned ll
#define all(x) x.begin(), x.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
const int N = 1e5 + 10;
const ll M = 998244353;


int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    map<ll, int> pos;
    pos[x] = 1;
    ll ans[m + 2], mpos = -1, len = 0, lpos = -1;
    ans[1] = x;
    ll suum = x;
    for (int i = 2; i <= min(n, m + 1); ++i) {
        ans[i] = (ans[i - 1] * ans[i - 1]) % m;
        suum += ans[i];
        if (pos.find(ans[i]) == pos.end())
            pos[ans[i]] = i;
        else {
            mpos = pos[ans[i]];
            len = i - mpos;
            lpos = i;
            break;
        }
    }
    if (mpos == -1)
        return cout << suum << endl, 0;
    ll res = 0;
    for (int i = 1; i < mpos; ++i) {
        res += ans[i];
    }
    ll sum = ans[mpos];
    for (int i = mpos + 1; i < lpos; ++i) {
        sum += ans[i];
    }
    n -= mpos - 1;
    res += (n / len) * sum;
    n %= len;
    for (int i = mpos; i < mpos + n; ++i) {
        res += ans[i];
    }
    cout << res << endl;
}