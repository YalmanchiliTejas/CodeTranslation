#include <iostream>
#include <string>
using namespace std;

int main() {
    string r, a, b;
    cin >> r >> a >> b;
    r += a;
    r += b;
    if (stoi(r) % 4 == 0) {
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}