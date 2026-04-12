#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a1, a2, b1, b2, c1, c2, d1, d2, e1, e2;
    while (cin >> a1 >> a2 && a1 && a2 && cin >> b1 >> b2 >> c1 >> c2 >> d1 >> d2 >> e1 >> e2) {
        int a = a1 + a2;
        int b = b1 + b2;
        int c = c1 + c2;
        int d = d1 + d2;
        int e = e1 + e2;
        int maxv = max({ a, b, c, d, e });
        if (maxv == a) cout << "A ";
        if (maxv == b) cout << "B ";
        if (maxv == c) cout << "C ";
        if (maxv == d) cout << "D ";
        if (maxv == e) cout << "E ";
        cout << maxv << endl;
    }
}
