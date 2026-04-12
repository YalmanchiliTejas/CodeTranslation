#include <bits/stdc++.h>
using namespace std;

int main() {
    string r, g, b; cin >> r >> g >> b;
    string s = g + b;
    int val = stoi(s);
    if (val%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
