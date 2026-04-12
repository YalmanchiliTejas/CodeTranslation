#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    string n;
    int k, z = 0;
    cin >> n >> k;
    int m = (int)n.length();
    if (k == 1) {
        z = (m - 1) * 9;
    } else if (k == 2) {
        if (m >= 2) z = (m - 1) * (m - 2) / 2 * 81;
    } else {
        if (m >= 3) z = (m - 1) * (m - 2) * (m - 3) / 6 * 729;
    }
    if (k == 1) {
        for (int i = 1; i <= 9; i++) {
            string t;
            t += (char)('0' + i);
            while (t.length() < m) t += '0';
            if (t <= n) z++;
        }
    } else if (k == 2) {
        for (int i = 1; i <= 9; i++) {
            string t;
            t += (char)('0' + i);
            while (t.length() < m) t += '0';
            for (int j = 1; j < m; j++) for (int g = 1; g <= 9; g++) {
                t[j] = g + '0';
                if (t <= n) z++;
                t[j] = '0';
            }
        }
    } else {
        for (int i = 1; i <= 9; i++) {
            string t;
            t += (char)('0' + i);
            while (t.length() < m) t += '0';
            for (int j = 1; j < m; j++) for (int g = 1; g <= 9; g++) {
                for (int k = j + 1; k < m; k++) for (int h = 1; h <= 9; h++) {
                    t[j] = g + '0';
                    t[k] = h + '0';
                    if (t <= n) z++;
                    t[j] = '0';
                    t[k] = '0';
                }
            }
        }
    }
    cout << z;
}
