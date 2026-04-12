#include <algorithm>
#include <iostream>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
    string S; cin >> S;
    string ans;
    if (S[0] == S[1] && S[1] == S[2]) {
        ans = "No";
    } else {
        ans = "Yes";
    }
    cout << ans << endl;
    return 0;
}