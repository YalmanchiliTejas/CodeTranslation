#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll ans = 0;

    sort(a.begin(), a.end());

    // 小さいものを中央にする
    deque<int> deq_s;
    int si = 0, bi = n;
    deq_s.push_back(a[0]);
    int t = 1;
    ll ans_s = 0;
    while (bi - si > 1) {
        if (t) {
            ans_s += abs(deq_s.front() - a[bi-1]) + abs(deq_s.back() - a[bi-2]);
            deq_s.push_front(a[bi-1]);
            deq_s.push_back(a[bi-2]);
            bi -= 2;
            t = 0;
        } else {
            ans_s += abs(deq_s.front() - a[si+1]) + abs(deq_s.back() - a[si+2]);
            deq_s.push_front(a[si+1]);
            deq_s.push_back(a[si+2]);
            si += 2;
            t = 1;
        }
    }
    if (bi - si > 1) {
        ans_s += max(abs(deq_s.front() - a[si+1]), abs(deq_s.back() - a[si+1]));
    }
    ans = max(ans_s, ans);

    // 大きいものを中央にする
    deque<int> deq_b;
    si = -1, bi = n-1;
    deq_b.push_back(a[n-1]);
    t = 0;
    ll ans_b = 0;
    while (bi - si > 1) {
        if (t) {
            ans_b += abs(deq_b.front() - a[bi-1]) + abs(deq_b.back() - a[bi-2]);
            deq_b.push_front(a[bi-1]);
            deq_b.push_back(a[bi-2]);
            bi -= 2;
            t = 0;
        } else {
            ans_b += abs(deq_b.front() - a[si+1]) + abs(deq_b.back() - a[si+2]);
            deq_b.push_front(a[si+1]);
            deq_b.push_back(a[si+2]);
            si += 2;
            t = 1;
        }
    }
    if (bi - si > 1) {
        ans_b += max(abs(deq_b.front() - a[si+1]), abs(deq_b.back() - a[si+1]));
    }
    ans = max(ans_b, ans);

    cout << ans << endl;
    return 0;
}