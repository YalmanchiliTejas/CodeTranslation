
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int res = 0;
    for (auto c : s) {
        if (c == 'A')
            res |= 1;
        else
            res |= 2;
    }

    if (res == 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}

