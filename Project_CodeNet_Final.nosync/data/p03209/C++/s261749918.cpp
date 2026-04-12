#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<ll, 51> LayerP;
array<ll, 51> LayerB;

ll bfs(ll layer, ll X)
{
    if (layer == 0) {
        // LV0バーガーはパティ1枚(LV1で再帰せずに処理されるはずなので、多分なくても良い)
        return 1;
    }

    // 最初のバン
    ll paty = 0;
    X--;
    if (X == 0) {
        return paty;
    }

    // 一つ下位レベルのバーガー
    if (X >= LayerP[layer - 1] + LayerB[layer - 1]) {
        paty += LayerP[layer - 1];
        X -= LayerP[layer - 1] + LayerB[layer - 1];
    } else {
        return paty + bfs(layer - 1, X);
    }
    if (X == 0) {
        return paty;
    }

    // 中央のパティ
    paty++;
    X--;
    if (X == 0) {
        return paty;
    }

    // 一つ下位のレベルのバーガー
    if (X >= LayerP[layer - 1] + LayerB[layer - 1]) {
        paty += LayerP[layer - 1];
        X -= LayerP[layer - 1] + LayerB[layer - 1];
    } else {
        return paty + bfs(layer - 1, X);
    }
    if (X == 0) {
        return paty;
    }

    // 最後のバン
    X--;
    return paty;
}

void main_()
{
    LayerP[0] = 1;
    LayerB[0] = 0;
    for (ll i = 1; i <= 50; ++i) {
        LayerP[i] = LayerP[i - 1] * 2 + 1;
        LayerB[i] = LayerB[i - 1] * 2 + 2;
    }

    ll N, X;
    cin >> N >> X;

    cout << bfs(N, X) << endl;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
