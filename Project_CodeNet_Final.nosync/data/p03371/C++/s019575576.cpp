#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include<map>
#include<set>
using namespace std;

string makeString(string s, int l, int r) {
    string t;
    t = s.substr(l, r );
    return t;
}
int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    if (a + b > 2 * c) {
        if (x < y) {
            if (b > 2 * c) cout << y * 2 * c << endl;
            else cout << x * c * 2 + (y - x) * b << endl;
        }
        else {
            if (a > 2 * c) cout << x * 2 * c << endl;
            else cout << y * c * 2 + (x - y) * a << endl;
        }
    }
    else  cout << x * a + y * b << endl;
}
