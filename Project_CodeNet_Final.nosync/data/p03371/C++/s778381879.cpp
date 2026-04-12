#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    //
    //  ABピザを 2t 枚買ったとすると、Aピザt枚、Bピザt枚に分割される
    //  Aピザにかかるお金 A(X - t / 2) + tC
    //  Bピザにかかるお金 B(Y - t / 2) + tC
    //  但し、 t / 2 の方が X, Y より大きかった時は、t で全部賄うとする
    //

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = INT_MAX;

    //  AB ピザを t 枚買ったとする
    //  t は、0 から　max(X, Y) * 2 まで動く
    for (int t = 0; t <= max(X, Y) * 2; t++) {
        int cur_cost = A * max(X - t / 2, 0) + B * max(Y - t / 2, 0) + t * C;
        if (ans >= cur_cost) {
            ans = cur_cost;
        } 
    }
    cout << ans << endl;
    return 0;
}
