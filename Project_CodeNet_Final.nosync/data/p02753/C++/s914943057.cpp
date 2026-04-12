#include <bits/stdc++.h>

using namespace std;

int main() {
    string S, c1, c2, c3;;
    cin >> S;
    c1 = S.substr(0,1);
    c2 = S.substr(1,1);
    c3 = S.substr(2,1);
    if (c1 == c2 && c1 == c3) cout << "No";
    else if (c1 != c2 && c1 == c3) cout << "Yes";
    else if (c1 == c2 && c1 != c3) cout << "Yes";
    else if (c2 == c1 && c2 != c3) cout << "Yes";
    else if (c2 != c1 && c2 == c3) cout << "Yes";
}