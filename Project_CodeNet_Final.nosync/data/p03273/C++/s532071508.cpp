#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;  //これで"std::cout"が"cout"と書ける

//MACRO
typedef long long ll;                  //64bit以上を表現可能な型
#define INF 100000000                  //ほぼ無限
#define itn int                        //タイポ対策
#define ALL(x) (x).begin(), (x).end()  //sort(all(x))などとする
#define SZ(x) ((int)(x).size())        //size()簡略化
//repetition
#define FOR(i, p, b) for (int i = (p); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define repR(i, n) for (int i = n; i >= 0; i--)
//debug
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \<< " " << __FILE__ << endl;
template <class T>
bool chMAX(T &a, const T &b) {  //aよりbが大きければaに代入
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chMIN(T &a, const T &b) {  //aよりbが小さければaに代入
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

//
//
//

int main() {
    int h, w;
    bool flag = false;
    cin >> h >> w;

    bool H[h] = {false};
    bool W[w] = {false};

    string a[h];

    rep(i, h) {
        cin >> a[i];
    }

    rep(i, h) {
        rep(j, w) {
            if (a[i][j] == '#') {
                H[i] = true;
                W[j] = true;
            }
        }
    }

    rep(i, h) {
        if (H[i]) {
            rep(j, w) {
                if (W[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }

}