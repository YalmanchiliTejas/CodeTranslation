#include <bits/stdc++.h>
#define rep(i, N) for (int i = 0; i < N; i++)
using namespace std;

int main()
{
    int A, B, C, X, Y, ans1, ans2, ans3;
    cin >> A >> B >> C >> X >> Y;
    pair<int, int> a, b;
    a = make_pair(X, A);
    b = make_pair(Y, B);

    ans1 = C * 2 * max(X, Y);
    ans2 = C * 2 * min(X, Y) + abs(Y - X) * max(a, b).second;
    ans3 = A * X + B * Y;
    cout << min(ans1, min(ans2, ans3)) << endl;
}