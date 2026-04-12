#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    char c; cin >> c;
    string s = "753";
    cout << (s.find(c) != s.npos ? "YES" : "NO") << endl;
    return 0;
}
