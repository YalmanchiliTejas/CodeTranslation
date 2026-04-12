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
    int a, b, c;
    cin >> a >> b >> c;
    cout << ((b * 10 + c) % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}
