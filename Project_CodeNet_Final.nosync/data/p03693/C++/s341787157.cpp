#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int a;
    a = r * 100 + g * 10 + b;
    a %= 4;
    if(a == 0){
        cout << "YES" << endl;
    }
    else if( a != 0){
        cout << "NO" << endl;
    }

}
