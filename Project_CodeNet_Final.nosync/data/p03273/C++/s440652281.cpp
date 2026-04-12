#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, m, b[102] = {}, c[102] = {};
    string s[102] = {};
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (s[i][j] == '#') b[i] = c[j] = 1;
    for (int i = 0; i < n; i++) if (b[i]) {
        for (int j = 0; j < m; j++) if (c[j]) cout << s[i][j];
        cout << '\n';
    }
}
