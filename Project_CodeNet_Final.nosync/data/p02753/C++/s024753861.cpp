#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main(int, char**) {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] == 'A')
            ++a;
        else
            ++b;
    }
    if (a == 3 || b == 3)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    
    return 0;
}