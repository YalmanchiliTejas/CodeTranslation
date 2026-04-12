#include <bits/stdc++.h>

#define rep(l, r) for (int i = (l); i < (r); i++)

typedef long long ll;
 
using namespace std;

int main() {
    string s;
    cin >> s;

    set<char> cs;
    rep(0, 3) cs.insert(s[i]);

    cout << (1 < cs.size() ? "Yes" : "No") << endl;

    return 0;
}
