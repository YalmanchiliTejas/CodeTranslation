#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;
    bool ans = (s[0] == s[1] && s[1] == s[2]);
    if (ans) puts("No");
    else puts("Yes");
}
