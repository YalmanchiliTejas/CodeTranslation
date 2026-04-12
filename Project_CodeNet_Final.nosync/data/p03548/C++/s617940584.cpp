#include <bits/stdc++.h>
#ifdef DEBUG
#include "_debug.cpp"
#include "callable.hpp/callable.hpp"
#endif
#define endl '\n'
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y, z;
    cin >> x >> y >> z;
    cout << (x - z) / (y + z) << endl;
    return 0;
}
