#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s, t;
    cin >> n >> s;
    s += s[0];
    for (int a = 0; a < 4; a++) {
        if (a == 0) t = "SS";
        else if (a == 1) t = "SW";
        else if (a == 2) t = "WS";
        else t = "WW";
        for (int i = 2; i <= n + 1; i++) {
            if (t[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    if (t[i - 2] == 'S') t += 'S';
                    else t += 'W';
                } else {
                    if (t[i - 2] == 'S') t += 'W';
                    else t += 'S';
                }
            } else {
                if (s[i - 1] == 'o') {
                    if (t[i - 2] == 'S') t += 'W';
                    else t += 'S';
                } else {
                    if (t[i - 2] == 'S') t += 'S';
                    else t += 'W';
                }
            }
        }
        if (t[0] == t[n] && t[1] == t[n + 1]) {
            cout << t.substr(0, n);
            return 0;
        }
    }
    cout << -1;
}
