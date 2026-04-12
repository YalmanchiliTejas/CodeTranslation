#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    string S; cin >> S;
    bool ok = false;
    if (S[0] != S[1]) ok = true;
    if (S[1] != S[2]) ok = true;
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}