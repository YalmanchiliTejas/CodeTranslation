#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S;
    cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) cout << "No" << "\n";
    else cout << "Yes" << "\n";
    return 0;
}