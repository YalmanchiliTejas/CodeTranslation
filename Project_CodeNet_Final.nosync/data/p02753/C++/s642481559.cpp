#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll mod = 1000000007;
const double eps = 1e-8;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

int main() {
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}