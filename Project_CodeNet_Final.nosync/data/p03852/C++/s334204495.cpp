#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s = "aiueo";
    char c; cin >> c;
    for (auto e: s) {
        if (e == c) {
            cout << "vowel" << endl;
            return 0;
        }
    }
    cout << "consonant" << endl;
    return 0;
}
