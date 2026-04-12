#include <iostream>

using namespace std;

int main() {
    string r, g, b;
    int n;
    cin >> r >> g >> b;
    n = stoi(r + g + b);
    if(n % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

