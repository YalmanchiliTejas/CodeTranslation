#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    int r, g, b, temp;
    cin >> r >> g >> b;
    temp = 100 * r + 10 * g + b;
    if(temp % 4) cout << "NO" << endl;
    else cout << "YES" << endl;
}