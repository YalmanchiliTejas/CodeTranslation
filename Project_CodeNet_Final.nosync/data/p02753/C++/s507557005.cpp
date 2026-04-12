#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

const int N = 3;
int main() {
    string s;
    cin >> s;

    string r = "No";
    for (int i=1; i < N; i++) {
        if (s[i-1] != s[i]) {
            r = "Yes";
            break;
        }
    }
    cout << r << endl;
    return 0;
}
