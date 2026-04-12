#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

#define CIN(T, x) T x; cin >> x;
#define CINS(T, x, N) vector<T> x(N); for(int i = 0; i < (N); i++) { cin >> x[i]; }
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << "\n";
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << "\n";


int main() {

    CIN(int, n);

    vector<vector<int>> alpha(26, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            alpha[ s[j]-'a' ][i]++;
        }
    }

    string ans = "";

    for (int i = 0; i < 26; i++) {
        int MIN = 1e9;
        for (int j = 0; j < n; j++) {
            MIN = min(MIN, alpha[i][j]);
        }
        if ( MIN > 0 ) {
            ans += string(MIN, 'a'+i);
        }
    }

    cout << ans << "\n";
    return 0;
}