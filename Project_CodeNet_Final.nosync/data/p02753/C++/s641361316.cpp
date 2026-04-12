#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    bool ok = false;
    for (int i = 0; i < 2; i++) if (s[i] != s[i+1]) ok = true;
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}