#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    string S;
    cin >> S;

    int a = 0, b = 0;
    rep(i, S.size()) {
        if (S[i] == 'A')
            a++;
        else
            b++;
    }

    if (a >= 1 && b >= 1)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;

    return 0;
}