#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
typedef long long ll;

int main() {
    string S; cin >> S;
    if(S[0] == S[1] && S[1] == S[2] && S[2] == S[0]) cout << "No" << endl;
    else cout << "Yes" << endl;
}