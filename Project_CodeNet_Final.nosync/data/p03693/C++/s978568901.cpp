#include <bits/stdc++.h>
#define endl '\n';

typedef long long ll;

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    const string YES = "YES";
    const string NO  = "NO";
    int r, g, b;

    cin >> r >> g >> b;

    r *= 10;
    r += g;
    r *= 10;
    r += b;

    if (r % 4 == 0) {
        cout << YES;
    } else {
        cout << NO;
    }
    cout << endl;

    return 0;
}

