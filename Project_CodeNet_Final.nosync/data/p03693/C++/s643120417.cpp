#include <bits/stdc++.h>
using namespace std;

int main() {

    int r, g, b, total;
    cin >> r >> g >> b;

    total = 100*r + 10*g + b;

    if(total %4 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}