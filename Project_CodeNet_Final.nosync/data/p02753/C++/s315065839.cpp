#include <bits/stdc++.h>
#define rep(i, N) for (int i = 0; i < (N); i++)
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;

    bool ok = true;
    if (S[0] == S[1] && S[1] == S[2]) ok = false;

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
