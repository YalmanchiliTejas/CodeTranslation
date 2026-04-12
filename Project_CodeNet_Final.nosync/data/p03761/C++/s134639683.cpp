#include <bits/stdc++.h>
using namespace std;

int alpha_to_int(char a) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    return alpha.find(a);
}

char int_to_alpha(int i) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    return alpha.at(i);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cnt(n+1, vector<int>(26));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        while(s.size()) {
            int j = alpha_to_int(s.back());
            cnt[i][j]++;
            s.pop_back();
        }
    }
    for (int j = 0; j < 26; j++) {
        cnt[n][j] = 51;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[n][j] = min(cnt[i][j], cnt[n][j]);
        }
    }
    string ans;
    for (int j = 0; j < 26; j++) {
        int sum_cnt = cnt[n][j];
        if (sum_cnt > 0) {
            for (int i = 0; i < sum_cnt; i++) {
                ans += int_to_alpha(j);
            }
        }
    }
    cout << ans << endl;
}