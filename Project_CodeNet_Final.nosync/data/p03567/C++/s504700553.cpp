#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    char s[6];
    cin >> s;

    cout << (strstr(s, "AC") ? "Yes" : "No") << endl;

    return 0;
}