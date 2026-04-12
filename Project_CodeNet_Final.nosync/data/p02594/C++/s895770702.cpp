#include<bits/stdc++.h>
using namespace std;

int main()
{

#ifdef _d
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    int x;
    cin >> x;
    if (x >= 30) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

#ifdef _d
    cerr << "Time: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
#endif

    return 0;
}
