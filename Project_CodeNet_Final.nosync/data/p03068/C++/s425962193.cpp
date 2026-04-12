#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    
    int n, k;
    string s;

    cin >> n >> s >> k;
    
    string an = "";

    for (int i = 0; i < n; ++i) {
        if (s[i] != s[k - 1]) {
            an += '*';
        } else {
            an += s[i];
        }
    }

    cout << an;

    return 0;
}
