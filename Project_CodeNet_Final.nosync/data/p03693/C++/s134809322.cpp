#include <iostream>
using namespace std;
int main() {
    int g, b;
    cin >> g >> g >> b;
    cout << ((10 * g + b) % 4 ? "NO" : "YES") << endl;
}