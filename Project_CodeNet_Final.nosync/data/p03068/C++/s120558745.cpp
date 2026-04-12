#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k;
    char safe = s[k-1];
    for (auto& i: s) {
        if (i != safe) i = '*';
    }
    cout << s << endl;
}