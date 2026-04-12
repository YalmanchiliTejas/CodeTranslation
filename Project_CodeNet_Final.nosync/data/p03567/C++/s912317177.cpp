#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;


int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'A' && s[i+1] == 'C') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
