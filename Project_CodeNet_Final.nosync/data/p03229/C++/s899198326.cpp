#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(int i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    ll ans[2];
    int l, r;
    int lv, rv, cnt = 0;
    bool mins = true;
    vector<int> nv(2), diff(2);
    if (n == 2) {
        cout << (a[1] - a[0]) << endl;
        return 0;
    }
    rep(i, 2) {
        l = 0; r = n - 1;
        ans[i] = 0;
        if (i == 0) {
            mins = true;
            ans[i] += abs(a[n - 1] - a[0]);
            ans[i] += abs(a[n - 2] - a[0]);
            lv = a[n - 2];
            rv = a[n - 1];
            l++;
            r -= 2;
        }
        else {
            mins = false;
            ans[i] += abs(a[0] - a[n - 1]);
            ans[i] += abs(a[1] - a[n - 1]);
            lv = a[0];
            rv = a[1];
            l += 2;
            r--;
        }
        cnt = 3;
        while(cnt < n) {
            if ((cnt + 1) == n) {
                ans[i] += max(abs(lv - (mins ? a[l] : a[r])), abs(rv - (mins ? a[l] : a[r])));
                cnt++;
                break;
            }
            if (mins) {
                nv[0] = a[l];
                nv[1] = a[l + 1];
                l += 2;
            }
            else {
                nv[0] = a[r];
                nv[1] = a[r - 1];
                r -= 2;
            }
            cnt += 2;
            diff[0] = abs(nv[0] - lv) + abs(nv[1] - rv);
            diff[1] = abs(nv[1] - lv) + abs(nv[0] - rv);
            lv = nv[0];
            rv = nv[1];
            ans[i] += max(diff[0], diff[1]);
            mins = !mins;
        }
    }
    
    cout << max(ans[0], ans[1]) << endl;
    return 0;
}