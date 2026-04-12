#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n;i++)

int main()
{
    int A, B, C;
    long X, Y;
    cin >> A >> B >> C >> X >> Y;

    long ans1 = A * X + B * Y;
    long ans2 = (2 * C) * X + B * ((Y - X) < 0 ? 0 : (Y - X));
    long ans3 = A * ((X - Y) < 0 ? 0 : (X - Y)) + (2 * C) * Y;

    cout << min(min(ans1, ans2), min(ans2, ans3)) << endl;
}