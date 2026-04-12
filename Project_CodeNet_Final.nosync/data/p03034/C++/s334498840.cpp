#include<iostream>
#include<vector>
#include<string>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= end; --i)
#define iter(i, c) for (auto i = (c).begin(); i != (c).end(); ++i)
#define riter(i, c) for (auto i = (c).rbegin(); i != (c).rend(); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> S(N);
    rep(i, 0, N) cin >> S[i];
    ll ans = 0;
    rep(C, 1, N) {
        ll now_ans = 0;
        if ((N - 1) % C) {
            for (int x = 0; N - 1 - C * x >= C; ++x) {
                now_ans += S[C * x] + S[N - 1 - C * x];
                ans = max(ans, now_ans);
            }
        }
        else {
            for (int x = 0; N - 1 - C * x > C * x; ++x) {
                now_ans += S[C * x] + S[N - 1 - C * x];
                ans = max(ans, now_ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}