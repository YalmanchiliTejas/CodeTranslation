#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define int long long

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, s;
    cin >> a >> s;

    if (a == s)
    {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
}
