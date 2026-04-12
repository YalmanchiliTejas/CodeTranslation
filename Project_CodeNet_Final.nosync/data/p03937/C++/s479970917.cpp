#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

void main_()
{
    ll H, W;
    cin >> H >> W;
    vector<string> ass;
    for (ll i = 0; i < H; ++i) {
        string s;
        cin >> s;
        ass.push_back(move(s));
    }

    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < W; ++j) {
            if (ass[i][j] != '#')
                continue;
            if ((i > 0 && j > 0 && ass[i - 1][j] == ass[i][j - 1])
                || (i < H - 1 && j < W - 1 && ass[i + 1][j] == ass[i][j + 1])) {
                cout << "Impossible\n";
                return;
            }
        }
    }
    cout << "Possible\n";
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);
    main_();
    return 0;
}
