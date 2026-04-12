#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int a, b, c;
    cin >> a >> b >> c;
    a *= 100;
    b *= 10;
    c += a + b;
    if (c % 4)cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
    
}



