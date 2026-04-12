#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<string> vs(N);
    for (int i = 0; i < N; i++) {
        cin >> vs[i];
    }

    Vi nums(26, I_INF);
    Vi cnts(26);
    for (int i = 0; i < N; i++) {
        cnts.assign(26, 0);
        for (const auto& c : vs[i]) {
            ++cnts[c - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            nums[i] = min(nums[i], cnts[i]);
        }
    }

    string ans;
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        for (int j = 0; j < nums[i]; j++) {
            ans += c;
        }
    }

    cout << ans << "\n";

    return 0;
}