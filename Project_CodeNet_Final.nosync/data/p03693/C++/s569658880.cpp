#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int r, g, b;
    cin >> r >> g >> b;
    int a = r * 100 + g * 10 + b;
    if (!(a % 4)) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}