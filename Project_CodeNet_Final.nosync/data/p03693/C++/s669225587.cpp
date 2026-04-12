#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int r, g, b;
    cin >> r >> g >> b;
    cout << (((r * 100 + g * 10 + b) % 4) ? "NO" : "YES") << endl;
}

