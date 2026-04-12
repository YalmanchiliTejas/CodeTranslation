//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    string S; cin >> S;
    if (S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}


int main() {
    solve();
    return 0;
}