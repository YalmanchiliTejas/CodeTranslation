#pragma region def
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using llint = long long;
using vint = vector<int>;
using vvint = vector<vector <int>>;
using pint = pair<int, int>;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const long long llINF = 1e18;
#pragma endregion

int main () {
    string s;
    cin >> s;
    if (s[0] == 'A' && s[1] == 'A' && s[2] == 'A' ||
    s[0] == 'B' && s[1] == 'B' && s[2] == 'B') {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
    return 0;
}