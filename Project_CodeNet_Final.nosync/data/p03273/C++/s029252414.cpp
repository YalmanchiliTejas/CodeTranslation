#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> a(0, vector<char>(w));

    rep(i, h) {
        bool white_flg = true;
        vector<char> tmp_a(w);
        rep(j, w) {
            cin >> tmp_a[j];
            if ( tmp_a[j] == '#' ) {
                white_flg = false;
            }
        }
        if ( !white_flg ) {
            a.push_back(tmp_a);
        }
    }


    vector<int> ignore_num;
    rep(i, w) {
        bool white_flg = true;
        rep(j, a.size()) {
            if ( a[j][i] == '#' ) {
                white_flg = false;
            }
        }
        if ( white_flg ) {
            ignore_num.push_back(i);
        }
    } 

//    rep(i, ignore_num.size()) {
//        cout << ignore_num[i] << endl;
//    }

    rep(i, a.size()){
        rep(j, w) {
            bool ignore_flg = false;
            if ( !ignore_num.empty() ) {
                rep(k, ignore_num.size()) {
                    if ( j == ignore_num[k] ) {
                        ignore_flg = true;
                    }
                }
            }
            if ( !ignore_flg ) printf("%c", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}