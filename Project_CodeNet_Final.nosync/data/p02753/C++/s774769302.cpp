#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[2] = {0, 0};
    string s;
    cin >> s;
    for (auto &ch : s) {
        ++cnt[ch - 'A'];
    }
    int num = 0;
    if (cnt[0]) {
        ++num;
    }
    if (cnt[1]) {
        ++num;
    }
    cout << ((num == 2) ? "Yes" : "No") << endl;
}