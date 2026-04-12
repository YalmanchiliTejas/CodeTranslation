#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int, int>;

const int cut = 998244353;

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> q(s+1);
    int ans = 0;
    rep(i,n) {
        q[0] += 1;  // q += 1;
        q[0] %= cut;
        { // q = (1 + x^a[i])
            vector<int> q2(s+1);
            rep(j,s+1) {
                q[j] %= cut;
                q2[j] += q[j];
                q2[j] %= cut;
                if (j+a[i] <= s) q2[j+a[i]] += q[j];
                q2[j+a[i]] %= cut;
            }
            q = q2;
        }
        ans += q[s];
        ans %= cut;
    }
    cout << ans << endl;
    return 0;
}