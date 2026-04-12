#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif

    string s;
    while (cin >> s) {
        bool f = s.find("AC") != -1;
        cout << (f ? "Yes" : "No") << endl;
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}