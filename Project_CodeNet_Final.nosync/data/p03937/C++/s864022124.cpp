// AtCoder Beginner Contest 054
#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
#define rep(i, n) for(int i = 0; i < (n); i++)
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}


int main()
{
    int H,W; cin >>H>>W;
    vs bd(H); cin >> bd;

    rep(h, H) {
        rep(w, W) {
            if (bd[h][w]=='#') {
                bool ok = true;
                if (!(h==0&&w==0)) {
                    if ((h > 0 && bd[h-1][w]=='#')==(w > 0 && bd[h][w-1]=='#')) {
                        ok = false;
                    }
                }
                if (!(h==H-1&&w==W-1)) {
                    if ((h < H-1 && bd[h+1][w]=='#')==(w < W-1 && bd[h][w+1]=='#')) {
                        ok = false;
                    }
                }
                if (!ok) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Possible" << endl;
}
