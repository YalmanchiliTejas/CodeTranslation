#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int cntA = 0;
    rep(i, 3) if (s[i] == 'A') cntA++;
    if (cntA != 3 && cntA != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}