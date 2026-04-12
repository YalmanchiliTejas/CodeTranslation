#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


string S;


void input() {
    cin >> S;
}


int main() {
    input();
    string ans = "No";
    rep(i, 2) {
        if (S[i] != S[i+1]) ans = "Yes";
    }
    cout << ans << endl;
}
