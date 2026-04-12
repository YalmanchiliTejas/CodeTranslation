#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    if ((r * 100 + g * 10 + b) % 4 == 0) cout << "YES\n";
    else cout << "NO\n";
}