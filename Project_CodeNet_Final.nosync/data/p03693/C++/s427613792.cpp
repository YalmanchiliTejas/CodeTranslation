#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, g, b;
    cin >> r >> g >> b;

    int num = r * 100 + g * 10 + b;

    cout << (num % 4 == 0 ? "YES" : "NO") << endl;
}