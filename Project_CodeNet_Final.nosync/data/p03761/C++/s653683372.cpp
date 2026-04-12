#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<vector<int>> cnt(n, vector<int>(30, 0));
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        //cout << s[i] << " ";
    }
    //cout << endl;

    for (int i = 0; i < n; i++) {
        string t = s[i];
        for (int j = 0; j < t.size(); j++) {
            cnt[i][t[j] - 'a']++;
            //cout << t[j] - 'a' << " ";
        }
        //cout << endl;
    }

    vector<int> mn(30, 0);
    for (int i = 0; i < 26; i++) {
        int a = 1e9;
        for (int j = 0; j < n; j++) {
            a = min(a, cnt[j][i]);
        }
        mn[i] = a;
    }

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            cout << cnt[i][j] << " ";
        }
        cout << endl;
    }
    */

    string ans = "";
    string abc = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 26; i++) {
        if (mn[i] == 0) continue;
        while (mn[i] > 0) {
            ans += abc[i];
            mn[i]--;
        }
    }

    cout << ans << endl;
    return 0;
}