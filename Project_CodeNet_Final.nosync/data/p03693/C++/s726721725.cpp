#include <iostream>

using namespace std;

int main() {
    int g, b;
    cin >> g >> g >> b;
    cout << ((g * 10 + b) % 4 ? "NO" : "YES") << endl;
    return 0;
}
