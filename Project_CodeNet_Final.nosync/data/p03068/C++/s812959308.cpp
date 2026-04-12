#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define REP(i, n) for(int i=0;i<n;i++)

typedef unsigned long ul;
using namespace std;

int n, k;
string s;

void solve() {
    string a = s;
    char hoge = s[k - 1];
    REP(i, n) {
        if (hoge != a[i]) {
            a[i] = '*';
        }
    }
    cout << a;
}

int main() {
    cin >> n >> s >> k;
    solve();
    return 0;
}
