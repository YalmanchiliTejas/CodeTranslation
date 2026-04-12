#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    char c = s[k - 1];
    for (int i = 0; i < n; i++) {
        if (s[i] == c) continue;
        s[i] = '*';
    }
    cout << s << endl;
    return 0;
}
