#include <bits/stdc++.h>
using namespace std;

int main() {
    map<char, int> mp;
    for (int i = 0; i < 3; ++i) {
        char c;  cin >> c;
        ++mp[c];
    }
    cout << (mp.size() == 2 ? "Yes" : "No") << endl;
}
