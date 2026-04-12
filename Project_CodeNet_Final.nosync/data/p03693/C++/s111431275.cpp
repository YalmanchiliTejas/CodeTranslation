#include <iostream>

using namespace std;

int main() {
    string rgb(3, ' ');
    cin >> rgb[0] >> rgb[1] >> rgb[2];
    int i = stoi(rgb);
    if (i % 4 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}