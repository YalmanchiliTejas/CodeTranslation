//Edson version
#include <bits/stdc++.h>

using namespace std;

void solve(int X)
{
    bool ans = (X == 3) or (X == 5) or (X == 7);

    cout << (ans ? "YES" : "NO") << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    int X;
    cin >> X;

    solve(X);

    return 0;
}