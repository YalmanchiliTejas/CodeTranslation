#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
using namespace std;
using ll = unsigned long long;
using p = pair<int, int>;

int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = INT_MAX;

    rep(i, 0, max(X, Y) + 1)
    {
        // Cの購入数を2iとしたときの、A, Bの購入数を求める
        // Cを使ってA, Bをいくつ作ったかと考えると、理解が進んだ
        int amount = (C * 2 * i) + (A * max(0, X - i)) + (B * max(0, Y - i));

        ans = min(ans, amount);
    }

    std::cout << ans << endl;

    return 0;
}
