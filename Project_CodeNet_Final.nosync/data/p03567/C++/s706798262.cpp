#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
constexpr int M = 1e9 + 7;
constexpr int INF = 1e9;

int main() {
    string s;
    cin >> s;
    bool ok = false;
    for(int i = 0; i < s.size() - 1; ++i) {
        if(s[i] == 'A' && s[i + 1] == 'C') {
            ok = true;
        }
    }
    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
