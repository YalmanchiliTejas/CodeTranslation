#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k;
    string s;
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++) {
        if (s[i] != s[k - 1]) s[i] = '*';
    }
    cout << s << endl;
}