#include <iostream>
#include <string>

using namespace std;

int main() {
    string r, g, b;
    cin >> r >> g >> b;

    string s = r + g + b;
    if (stoi(r+g+b) % 4 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}