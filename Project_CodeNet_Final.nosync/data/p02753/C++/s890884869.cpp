#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;
    vector<int> cnt(2);
    for (char c : s) cnt[c - 'A']++;
    if (cnt[0] && cnt[1]) cout << "Yes\n";
    else cout << "No\n";
}