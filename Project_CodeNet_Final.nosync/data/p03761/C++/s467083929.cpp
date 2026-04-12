#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int a[51][27];
int b[27];


int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); ++j) {
            a[i][s[j]-'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        int t = 51;
        for (int j = 0; j < n; ++j) {
            t = min(a[j][i], t);
        }
        b[i] = t;
    }
    for (int i = 0; i < 26; ++i) {
        if (b[i] > 0) {
            char c = 'a'+i;
            while (b[i] > 0) {
                cout << c;
                b[i]--;
            }
        }
    }
    cout << endl;
    return 0;
}
