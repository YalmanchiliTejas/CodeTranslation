#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string S;
    vector<int> dct1(26);
    vector<int> dct2(26);
    cin >> S;
    for (int j = 0; j < S.length(); j++) {
        dct1[S[j] - 'a'] += 1;
    }
    //それ以降とのmin
    for (int i = 1; i < n; i++) {
        cin >> S;
        for (int j = 0; j < S.length(); j++) {
            dct2[S[j] - 'a'] += 1;
        }
        for (int j = 0; j < dct1.size(); j++) {
            dct1[j] = min(dct1[j], dct2[j]);
        }
        fill(dct2.begin(), dct2.end(), 0);
    }
    string ans = "";
    for (int i = 0; i < dct1.size(); i++) {
        for (int j = 0; j < dct1[i]; j++) {
            ans += ('a' + i);
        }
    }
    cout << ans << endl;
}