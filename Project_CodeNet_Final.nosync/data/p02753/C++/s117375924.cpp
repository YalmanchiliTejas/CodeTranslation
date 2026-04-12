#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    string s;
    cin >> s;

    cout << (!(s[0] == s[1] && s[1] == s[2]) ? "Yes" : "No") << endl;

    return 0;
}