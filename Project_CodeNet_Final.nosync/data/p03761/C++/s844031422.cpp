#include <iostream>
#include <string.h>
using namespace std;
const int N_MAX = 50;
int main (void) {
    int n;

    cin >> n;
    int cnt[n][26];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        string S;
        cin >> S;
        for (int j = 0, len = S.length(); j < len; j++) {
            cnt[i][S[j] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        int mi = N_MAX;
        for (int j = 0; j < n; j++) {
            mi = min(mi, cnt[j][i]);
        }
        for (int j = 0; j < mi; j++) {
            char c = i + 'a';
            cout << c;
        }
    }
    cout << endl;

    return 0;
}
