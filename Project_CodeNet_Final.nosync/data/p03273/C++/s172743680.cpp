#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<(int)(b);++i)
#define rep(i,n) REP(i,0,n)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

using namespace std;
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> map(H, vector<int>(W));
    rep(i, H) {
        rep (j, W) {
            char a;
            cin >> a;
            map[i][j] = a == '.' ? 1 : 2;
        }
    }
    rep(i, H) {
        bool flg = false;
        rep (j, W) {
            bool flg1 = true;
            for (int k = 0; k < H; k++)
                if (map[k][j] == 2) flg1 = false;
            bool flg2 = true;
            for (int k = 0; k < W; k++)
                if (map[i][k] == 2) flg2 = false;
            if (!(flg1 || flg2)) {
                if (map[i][j] == 1)
                    cout << '.';
                else
                    cout << '#';
                flg = true;
            }
        }
        if (flg)
            cout << endl;
    }
    return 0;
}


