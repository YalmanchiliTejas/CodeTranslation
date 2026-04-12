#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-11;

bool bo[10][10];

int main() {
    while (1) {
        string s;
        cin >> s;
        if (s == "#") {
            break;
        }
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = 0; i < 10; i++) {
            fill(bo[i], bo[i] + 10, false);
        }
        int len = s.size();
        int row = 0;
        int col = 0;
        int brow = 0;
        int bcol = 0;
        for (int i = 0; i < len; i++) {
            if (s[i] == '/') {
                row++;
                bcol = col;
                col = 0;
            } else if (s[i] == 'b') {
                bo[row][col] = true;
                col++;
            } else {
                col += s[i] - '0';
            }
        }
        brow = row + 1;
        bo[a - 1][b - 1] = false;
        bo[c - 1][d - 1] = true;
        string ans = "";
        for (int i = 0; i < brow; i++) {
            char c = '0';
            for (int j = 0; j < bcol; j++) {
                if (bo[i][j]) {
                    if (c > '0') {
                        ans += c;
                    }
                    ans += 'b';
                    c = '0';
                } else {
                    c++;
                }
            }
            if (c > '0') {
                ans += c;
            }
            if (i != brow - 1) {
                ans += '/';
            }
        }
        cout << ans << endl;
    }
}

