#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

int main() {
    //freopen("input.txt", "r", stdin);

    int a, b, c;
    cin >> a >> b >> c;

    int x = 100 * a + 10 * b + c;

    if(x % 4 == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << "\n"; return 0;
}
