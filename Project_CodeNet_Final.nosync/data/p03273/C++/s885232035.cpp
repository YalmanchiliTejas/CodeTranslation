#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for (auto &s : A) cin >> s;

    vector<int> X, Y;
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (A.at(y).at(x) == '#') {
                X.push_back(x);
                Y.push_back(y);
            }
        }
    }
    vector<int> TX = X, TY = Y;
    sort(TX.begin(), TX.end());
    sort(TY.begin(), TY.end());
    TX.erase(unique(TX.begin(), TX.end()), TX.end());
    TY.erase(unique(TY.begin(), TY.end()), TY.end());
    int R = TY.size();
    int C = TX.size();
    vector<vector<char> > B(R, vector<char>(C, '.'));
    for (int i = 0; i < X.size(); ++i) {
        int y = lower_bound(TY.begin(), TY.end(), Y.at(i)) - TY.begin();
        int x = lower_bound(TX.begin(), TX.end(), X.at(i)) - TX.begin();
        B.at(y).at(x) = '#';
    }

    for (auto &V : B) {
        for (auto &c : V) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}