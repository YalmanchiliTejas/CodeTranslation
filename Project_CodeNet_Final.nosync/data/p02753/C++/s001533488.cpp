#include<bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i) {
    	if (s[i] == 'A') ++a;
    	else ++b;
    }
    if (a > 0 && b > 0) cout << "Yes\n";
    else cout << "No\n";
}