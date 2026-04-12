#include <bits/stdc++.h>
using namespace std;
typedef int64_t Int;
#define dump(x) cout << (x) << '\n'
Int mod = 1e9+7;
//Int mod = 998244353; 


int main() {
    Int n, k;
    string s;
    cin >> n >> s >> k;
    char a = s[k - 1];
    for (Int i = 0; i < n; i++) {
        if (a == s[i]) {
            cout << s[i];
        }
        else {
            cout << '*';
        }
    }
    cout << endl;
    return 0;
}