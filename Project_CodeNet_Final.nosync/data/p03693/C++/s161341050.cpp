#include <iostream>
#include <string>
#include <cstdlib>
#include <typeinfo>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    string s  = to_string(r) + to_string(g) + to_string(b);
    int t = atoi(s.c_str());
    if (t % 4 == 0) {
	cout << "YES" << endl;
    } else {
	cout << "NO" << endl;
    }
}
