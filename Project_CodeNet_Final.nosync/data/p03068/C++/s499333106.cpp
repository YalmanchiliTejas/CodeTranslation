#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    int k;
    cin >> n >> s >> k;

    char skey = s[k-1];
    for (int i = 0; i < n; i++) {
        if (skey != s[i]) {
            cout << '*';
        }
        else cout << s[i];
    }

    cout << endl;

    return 0;
}