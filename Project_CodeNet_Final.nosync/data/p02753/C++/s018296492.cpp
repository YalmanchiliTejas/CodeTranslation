#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    string s; cin >> s;
    for (int i = 0; i < 2; i++) {
        if (s[i] != s[i + 1]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}