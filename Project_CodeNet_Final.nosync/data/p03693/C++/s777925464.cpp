#include<bits/stdc++.h>
using namespace std;

int main(){
    int r, g, b;
    cin >> r >> g >> b;

    int rgb = r * 100 + g * 10 + b;
    cout << (rgb % 4 == 0 ? "YES" : "NO") << endl;
}