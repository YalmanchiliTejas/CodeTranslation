#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r, g, b, n;
    cin >> r >> g >> b;
    n = g * 10 + b;
    if(n % 4 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}