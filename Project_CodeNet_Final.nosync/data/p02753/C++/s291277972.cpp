#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    cout << (S[0] == S[1] && S[1] == S[2] ? "No\n" : "Yes\n");

    return 0;
}