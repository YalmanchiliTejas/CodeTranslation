#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int X;

int main() {
    cin >> X;

    string ans = "NO";
    if (X == 3 || X == 5 || X == 7) {
        ans = "YES";
    }

    cout << ans << endl;
}