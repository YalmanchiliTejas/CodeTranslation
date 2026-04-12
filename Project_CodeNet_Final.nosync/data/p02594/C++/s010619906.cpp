#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";

const string NO = "No";

void solve(int X)
{
    if (X >= 30)
        cout << YES << endl;
    else
        cout << NO << endl;
}

int main()
{
    int X;
    cin >> X;
    solve(X);
    return 0;
}
