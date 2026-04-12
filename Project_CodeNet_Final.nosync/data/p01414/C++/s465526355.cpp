//=================================
// Created on: 2018/07/02 20:16:19
//=================================
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin >> N;
    using P = pair<int, int>;
    vector<P> s(N);
    for (int i = 0, H, W; i < N; i++) { cin >> H >> W, s[i] = {H, W}; }
    vector<vector<int>> f(4, vector<int>(4, 0));
    map<char, int> mp;
    mp['R'] = 1, mp['G'] = 2, mp['B'] = 3;
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; j++) { f[i][j] = mp[s[j]]; }
    }
    vector<int> memo(1 << 16, -1);
    auto dfs = [&](auto&& self, const int hash) -> int {
        if (hash == 0) { return 0; }
        if (memo[hash] != -1) { return memo[hash]; }
        int ans = 16;
        for (int i = 0; i < N; i++) {
            const int H = s[i].first, W = s[i].second;
            for (int h = 1 - H; h < 4; h++) {
                for (int w = 1 - W; w < 4; w++) {
                    const int hinf = max(h, 0), winf = max(w, 0);
                    const int hsup = min(h + H, 4), wsup = min(w + W, 4);
                    set<int> ch;
                    for (int i = hinf; i < hsup; i++) {
                        for (int j = winf; j < wsup; j++) {
                            if (hash & (1 << (4 * i + j))) { ch.insert(f[i][j]); }
                        }
                    }
                    if (ch.size() != 1) { continue; }
                    int h = hash;
                    for (int i = hinf; i < hsup; i++) {
                        for (int j = winf; j < wsup; j++) { h &= ~(1 << (4 * i + j)); }
                    }
                    const int sub = self(self, h) + 1;
                    ans = min(ans, sub);
                }
            }
        }
        return memo[hash] = ans;
    };
    const int ans = dfs(dfs, (1 << 16) - 1);
    cout << ans << endl;
    return 0;
}

