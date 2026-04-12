#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

int main()
{
    int H,W;
    cin >> H >> W;

    vector<vector<char>> a(H, vector<char>(W));

    vector<bool> deletedRow(H, true);
    vector<bool> deletedCol(W, true);

    rep(i, H) rep(j, W) {
        cin >> a[i][j];
        if(a[i][j] == '#'){
            deletedRow[i] = false;
            deletedCol[j] = false;
        }
    }

    rep(i, H) {
        if(!deletedRow[i]){
            rep(j, W) {
                if(!deletedCol[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
}
