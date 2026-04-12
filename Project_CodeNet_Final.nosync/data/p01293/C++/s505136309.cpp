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

int dig(char a) {
    if (isdigit(a)) {
        return a - '0';
    } else {
        if (a == 'T') {
            return 10;
        } else if (a == 'J') {
            return 11;
        } else if (a == 'Q') {
            return 12;
        } else if (a == 'K') {
            return 13;
        } else {
            return 14;
        }
    }
}

int main() {
    while (1) {
        string tru;
        cin >> tru;
        if (tru == "#") {
            break;
        }
        string card[4][13];
        bool trued[13];
        fill(trued, trued + 13, false);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                cin >> card[i][j];
                if (card[i][j][1] == tru[0]) {
                    trued[j] = true;
                }
            }
        }
        int num = 0;
        int oldwin = 0;
        for (int i = 0; i < 13; i++) {
            int win = -1;
            int maxnum = 0;
            if (trued[i]) {
                for (int j = oldwin; j < oldwin + 4; j++) {
                    if (card[j % 4][i][1] == tru[0]) {
                        //cout << dig(card[j][i][0]) << endl;
                        if (dig(card[j % 4][i][0]) > maxnum) {
                            win = j % 4;
                            maxnum = dig(card[j % 4][i][0]);
                        }
                    }
                }
                oldwin = win;
                if (win == 0 || win == 2) {
                    num++;
                    //cout << i << endl;
                }
            } else {
                char ttru = card[oldwin][i][1];
                for (int j = oldwin; j < oldwin + 4; j++) {
                    if (card[j % 4][i][1] == ttru) {
                        //cout << dig(card[j][i][0]) << endl;
                        if (dig(card[j % 4][i][0]) > maxnum) {
                            win = j % 4;
                            maxnum = dig(card[j % 4][i][0]);
                        }
                    }
                }
                oldwin = win;
                if (win == 0 || win == 2) {
                    num++;
                    //cout << i << endl;
                }
            }
        }
        if (num >= 7) {
            cout << "NS " << num - 6 << endl;
        } else {
            cout << "EW " << 7 - num << endl;
        }
    }
}

