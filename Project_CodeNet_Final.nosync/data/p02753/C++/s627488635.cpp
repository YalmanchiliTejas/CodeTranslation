#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    bool ok = false;
    for (int i = 0; i < 2; i++) {
        if (S[i] != S[i+1]) ok = true;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}