#include <iostream>
#include <string>

using namespace std;

int main() {
    char x;
    cin >> x;
    cout << (string("753").find(x) == string::npos ? "NO" : "YES") << endl;
    return 0;
}
