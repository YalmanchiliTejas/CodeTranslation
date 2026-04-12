#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
ll inf = 1e18;
int main() {
    string s;
    cin >> s;
    cout << (s[0] == s[1] && s[1] == s[2] ? "No" : "Yes") << endl;
    return 0;
}