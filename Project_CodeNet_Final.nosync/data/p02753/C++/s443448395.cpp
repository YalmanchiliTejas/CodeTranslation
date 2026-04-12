#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    string S;
    cin >> S;
    if(S[0] == S[1] && S[1] == S[2])
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
