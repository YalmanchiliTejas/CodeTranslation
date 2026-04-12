#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n;
    cin >> s;
    cin >> k;

    char c = s[k - 1];
    //cout << c << endl;
    for (int i = 0; i < n; i++) {
        if (s[i] != c) {
            s[i] = '*';
        }
    }
    cout << s << endl;

    return 0;
}
