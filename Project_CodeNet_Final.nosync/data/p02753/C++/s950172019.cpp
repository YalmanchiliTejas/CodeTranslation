#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;

    cin >> s;

    if(s.at(0) == s.at(1) && s.at(1) == s.at(2)) printf("No\n");
    else printf("Yes\n");

    return 0;
}