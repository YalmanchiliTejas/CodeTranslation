#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define imfor(i, n) for(int i = 0; i < n; i++)
using namespace std;
ll MOD = 1000000007;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string ans;
    bool f1 = false;
    bool f2 = false;
    //check SS
    ans = "";
    ans += "SS";
    for (int i = 2; i < s.size(); i++) {
        if (ans[i - 2] == 'S' && ans[i - 1] == 'S') {
            if (s[i - 1] == 'o') {
                ans += 'S';
            }
            else {
                ans += 'W';
            }
        }
        else if (ans[i - 2] == 'S' && ans[i - 1] == 'W') {
            if (s[i - 1] == 'o') {
                ans += 'W';
            }
            else {
                ans += 'S';
            }
        }
        else if (ans[i - 2] == 'W' && ans[i - 1] == 'S') {
            if (s[i - 1] == 'o') {
                ans += 'W';
            }
            else {
                ans += 'S';
            }
        }
        else if (ans[i - 2] == 'W' && ans[i - 1] == 'W') {
            if (s[i - 1] == 'o') {
                ans += 'S';
            }
            else {
                ans += 'W';
            }
        }
    }
    if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'S') {
        if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
            f1 = true;
        }
        else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
            f1 = true;
        }
    }
    else if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'W') {
        if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
            f1 = true;
        }
        else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
            f1 = true;
        }
    }
    else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'S') {
        if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
            f1 = true;
        }
        else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
            f1 = true;
        }
    }
    else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'W') {
        if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
            f1 = true;
        }
        else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
            f1 = true;
        }
    }
    if (s[0] == 'o' && ans[0] == 'S') {
        if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
            f2 = true;
        }
        else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
            f2 = true;
        }
    }
    else if (s[0] == 'o' && ans[0] == 'W') {
        if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
            f2 = true;
        }
        else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
            f2 = true;
        }
    }
    else if (s[0] == 'x' && ans[0] == 'S') {
        if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
            f2 = true;
        }
        else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
            f2 = true;
        }
    }
    else if (s[0] == 'x' && ans[0] == 'W') {
        if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
            f2 = true;
        }
        else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
            f2 = true;
        }
    }
    //check SW
    if (!f1 || !f2) {
        f1 = false;
        f2 = false;
        ans = "";
        ans += "SW";
        for (int i = 2; i < s.size(); i++) {
            if (ans[i - 2] == 'S' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    ans += 'S';
                }
                else {
                    ans += 'W';
                }
            }
            else if (ans[i - 2] == 'S' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o') {
                    ans += 'W';
                }
                else {
                    ans += 'S';
                }
            }
            else if (ans[i - 2] == 'W' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    ans += 'W';
                }
                else {
                    ans += 'S';
                }
            }
            else if (ans[i - 2] == 'W' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o') {
                    ans += 'S';
                }
                else {
                    ans += 'W';
                }
            }
        }
        if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'S') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'W') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'S') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'W') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
                f1 = true;
            }
        }
        if (s[0] == 'o' && ans[0] == 'S') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
                f2 = true;
            }
        }
        else if (s[0] == 'o' && ans[0] == 'W') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
                f2 = true;
            }
        }
        else if (s[0] == 'x' && ans[0] == 'S') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
                f2 = true;
            }
        }
        else if (s[0] == 'x' && ans[0] == 'W') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
                f2 = true;
            }
        }
    }
    //check WS
    if (!f1 || !f2) {
        f1 = false;
        f2 = false;
        ans = "";
        ans += "WS";
        for (int i = 2; i < s.size(); i++) {
            if (ans[i - 2] == 'S' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    ans += 'S';
                }
                else {
                    ans += 'W';
                }
            }
            else if (ans[i - 2] == 'S' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o') {
                    ans += 'W';
                }
                else {
                    ans += 'S';
                }
            }
            else if (ans[i - 2] == 'W' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    ans += 'W';
                }
                else {
                    ans += 'S';
                }
            }
            else if (ans[i - 2] == 'W' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o') {
                    ans += 'S';
                }
                else {
                    ans += 'W';
                }
            }
        }
        if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'S') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'W') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'S') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'W') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
                f1 = true;
            }
        }
        if (s[0] == 'o' && ans[0] == 'S') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
                f2 = true;
            }
        }
        else if (s[0] == 'o' && ans[0] == 'W') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
                f2 = true;
            }
        }
        else if (s[0] == 'x' && ans[0] == 'S') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
                f2 = true;
            }
        }
        else if (s[0] == 'x' && ans[0] == 'W') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
                f2 = true;
            }
        }
    }
    //check WW
    if (!f1 || !f2) {
        f1 = false;
        f2 = false;
        ans = "";
        ans += "WW";
        for (int i = 2; i < s.size(); i++) {
            if (ans[i - 2] == 'S' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    ans += 'S';
                }
                else {
                    ans += 'W';
                }
            }
            else if (ans[i - 2] == 'S' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o') {
                    ans += 'W';
                }
                else {
                    ans += 'S';
                }
            }
            else if (ans[i - 2] == 'W' && ans[i - 1] == 'S') {
                if (s[i - 1] == 'o') {
                    ans += 'W';
                }
                else {
                    ans += 'S';
                }
            }
            else if (ans[i - 2] == 'W' && ans[i - 1] == 'W') {
                if (s[i - 1] == 'o') {
                    ans += 'S';
                }
                else {
                    ans += 'W';
                }
            }
        }
        if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'S') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'o' && ans[s.size() - 1] == 'W') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'S') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'W') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'S')) {
                f1 = true;
            }
        }
        else if (s[s.size() - 1] == 'x' && ans[s.size() - 1] == 'W') {
            if (ans[0] == 'S' && ans[s.size() - 2] == 'S') {
                f1 = true;
            }
            else if ((ans[0] == 'W' && ans[s.size() - 2] == 'W')) {
                f1 = true;
            }
        }
        if (s[0] == 'o' && ans[0] == 'S') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
                f2 = true;
            }
        }
        else if (s[0] == 'o' && ans[0] == 'W') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
                f2 = true;
            }
        }
        else if (s[0] == 'x' && ans[0] == 'S') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'W') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'S')) {
                f2 = true;
            }
        }
        else if (s[0] == 'x' && ans[0] == 'W') {
            if (ans[1] == 'S' && ans[s.size() - 1] == 'S') {
                f2 = true;
            }
            else if ((ans[1] == 'W' && ans[s.size() - 1] == 'W')) {
                f2 = true;
            }
        }
    }
    if (f1 && f2) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
}