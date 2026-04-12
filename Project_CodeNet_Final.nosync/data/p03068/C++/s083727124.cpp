#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s;
    int K;
    cin >> n >> s >> K;
    K--;
    char tar = s[K];
    for (char& c : s) {
        c = (c == tar ? c : '*');
    }
    cout << s << endl;
    return 0;
}