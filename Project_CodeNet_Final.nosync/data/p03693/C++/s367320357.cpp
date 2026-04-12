#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if((100*r+10*g+b)%4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
