#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
