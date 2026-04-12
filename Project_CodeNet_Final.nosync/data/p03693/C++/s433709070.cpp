#include <bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;
    int c = g * 10 + b;
    if (c % 4 == 0){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
       