#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main () {
    string s;
    cin >> s;
    if (s == "AAA" || s == "BBB") {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}