#include <bits/stdc++.h>
using namespace std;
int r, g, b;
int main() {
    cin >> r >> g >> b;
    int sum = r*100 + g*10 + b;
    if(sum % 4 == 0) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
}