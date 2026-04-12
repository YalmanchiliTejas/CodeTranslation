#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l;
    cin >> l;

    string s, t;
    cin >> s >> t;

    if (s + t > t + s) swap(s, t);

    int a = s.size(), b = t.size();
    int i1, j1;
    for (int i = 0; i <= l; i += a) {
        if ((l - i) % b == 0) {
            i1 = i / a;
            j1 = (l - i) / b;
        }
    }

    string r; r.reserve(l);
    for (int i = 0; i < i1; i++) {
        r += s;
    }
    for (int i = 0; i < j1; i++) {
        r += t;
    }

    cout << r << endl;

    return 0;
}