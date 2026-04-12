#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

#define cout (cout << setprecision(12))

int main() {
    string s;
    cin >> s;
    auto before = s[0];
    bool flag = false;
    for (int i = 1; i < s.size(); i++) {
        auto after = s[i];
        if (before != after) {
            flag = true;
            break;
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}