#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int n;

signed main() {
    int appear[26] = {};
    fill(appear, appear + 26, 100);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;
        int cur_appear[26] = {};
        for (int j = 0; j < S.length(); j++) {
            cur_appear[S[j] - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            appear[j] = min(appear[j], cur_appear[j]);
        }
    }
    for (int i = 0; i < 26; i++) {
        if (appear[i] == 100) {
            continue;
        }
        for (int j = 0; j < appear[i]; j++) {
            cout << (char)(i + 'a');
        }
    }
    cout << endl;
    return 0;
}
