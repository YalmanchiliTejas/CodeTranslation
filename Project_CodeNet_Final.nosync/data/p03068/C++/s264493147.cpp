#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; string s; int k;
    cin >> n >> s >> k;
    char x = s[k - 1];
    for (int i = 0; i < n; i++) {
        if (s[i] != x) s[i] = '*';
    }
    cout << s << endl;
    return 0;
}