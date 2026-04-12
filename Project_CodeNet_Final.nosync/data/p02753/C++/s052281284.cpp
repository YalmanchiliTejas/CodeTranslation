#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;
    if (s.at(0) == s.at(1) && s.at(1) == s.at(2)) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }
}