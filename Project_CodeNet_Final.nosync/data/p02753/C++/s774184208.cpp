#include <bits/stdc++.h>

using namespace std;

const int N = int(2e5) + 5;
const int MOD = int(1e9) + 7;
const int inf = int(2e9);

int main() {
    ios_base :: sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s;
    cin >> s;
    if (s[0] != s[1] || s[1] != s[2] || s[0] != s[2])
        cout << "Yes";
    else cout << "No";
    return 0;
}
