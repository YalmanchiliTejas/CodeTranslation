#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cstdio>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int) n; i++)

int main() {
    string s;
    cin >> s;
    bool a = false;
    bool b = false;
    rep(i,3) {
        if (s[i] == 'A') a = true;
        if (s[i] == 'B') b = true;
    }
    if (a && b) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}