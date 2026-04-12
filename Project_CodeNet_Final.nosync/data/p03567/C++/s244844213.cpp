#include <bits/stdc++.h>

using namespace std;


int main() {
    string S;
    cin >> S;

    auto ans = "No";
    for (int i = 0; i < S.size() - 1; ++i) {
        if (S[i] == 'A' && S[i + 1] == 'C') ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}