#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,n,m) for (int i = n; i < (m); ++i)
using namespace std;
using ll = long long;
using P = pair<int,string>;

int main() {
    string s; cin >> s;
    bool ans = ((s[0]==s[1]) && (s[0]==s[2]) && (s[2]==s[1]));
    cout << ((ans) ? "No" : "Yes") << endl;
    return 0;
}