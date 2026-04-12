#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    //判定する対象
    int k = 100 * r + 10 * g + b;
    if (k % 4 == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}