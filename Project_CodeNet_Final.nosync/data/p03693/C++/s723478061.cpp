#include <iostream>
using namespace std;

int main () {
    string r,g,b;
    cin >> r >> g >> b;
    string ns = "";
    ns += r;
    ns += g;
    ns += b;
    int n = atoi(ns.c_str());
    if (n%4 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
