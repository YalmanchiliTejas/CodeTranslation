#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int, int> P;
typedef long long ll;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));

    rep(i, h) rep(j, w) cin >> g[i][j];

    vector<bool> tate(w, false);
    vector<bool> yoko(h, false);

    rep(i, h)
    {
        rep(j, w)
        {
            if (g[i][j] == '#')
            {
                yoko[i] = true;
                tate[j] = true;
            }
        }
    }

    rep(i, h){
        if (yoko[i]){
            rep(j, w){
                if (tate[j]){
                    cout << g[i][j];
                }
            }
            cout << endl;
        }
    }
}