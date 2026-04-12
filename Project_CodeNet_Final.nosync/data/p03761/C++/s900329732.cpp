#include <bits/stdc++.h>
using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define ll long long

int main() {
    int n;
    cin >> n;
    int a[26] = {0};
    string t;
    cin >> t;
    for (char c : t) {
        a[c-'a']++;
    }
    for (int i = 1; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 26; j++) {
            a[j] = min((int)a[j], (int)count(s.begin(), s.end(), j+'a'));
        }
    }

    string ans;
    for (int i = 0; i < 26; i++) {
        ans += string(a[i], i+'a');
    }
    sort(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}