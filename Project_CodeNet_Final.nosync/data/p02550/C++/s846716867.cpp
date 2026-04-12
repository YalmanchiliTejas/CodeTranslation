// 9/19 リアルタイム参加
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, X, M;
    cin >> N >> X >> M;

    vector<ll> ans;
    ans.push_back(0);

    ll final_ans = 0;
    bool has_cycle = false;

    map<ll, ll> mp;  // firstの値のあまりがsecond回目に登場。

    ll now = X;
    ans.push_back(now % M);
    mp[now % M] = 1;

    for (ll index = 2; index <= N; index++) {
        now = (now * now) % M;
        if (mp[now] != 0) {
            ll prev = mp[now];
            ll cycle_sum = ans[index - 1] - ans[prev - 1];  // 1サイクルの和
            // ll cycle_num = now - prev;
            ll cycle_num = index - prev;

            // printf("prev, cycle_sum, cycle_num = %d, %d, %d\n", prev, cycle_sum, cycle_num);

            ll rest_num = N - index + 1;  // index自身も含む。
            // cout << "here?2" << endl;
            ll rest_sum = (rest_num / cycle_num) * cycle_sum;
            // cout << "here?3" << endl;
            ll rest_of_rest = rest_num % cycle_num;
            // cout << rest_of_rest << endl;
            for (ll i = 0; i < rest_of_rest; i++) {
                rest_sum += now;
                now = (now * now) % M;
            }

            // cout << "here?" << endl;

            final_ans = ans[index - 1] + rest_sum;
            has_cycle = true;
            break;
        } else {
            mp[now] = index;
            ans.push_back(ans.back() + now);
            // printf("now, index, ans = %d, %d, %d\n", now, index, ans.back());
        }
    }

    if (has_cycle) {
        cout << final_ans << endl;
    } else {
        cout << ans[N] << endl;
    }
}
