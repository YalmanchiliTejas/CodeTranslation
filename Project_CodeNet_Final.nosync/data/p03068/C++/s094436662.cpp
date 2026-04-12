#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string s;
    cin >> n >> s >> k;
    for (int i = 0; i < n; i++) {
        if (s[k-1] != s[i])
            cout << '*';
        else
            cout << s[i];
    }
    cout << endl;
    return 0;
}