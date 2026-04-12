#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define MAX 505
 
typedef long long ll;
typedef unsigned long long ull;
typedef bitset<64> bset;

bool make(vector< vector<bool> > s, vector< vector<bool> > u, vector< vector<int> > &a, int n)
{
    rep(i,n) rep(j,n) a[i][j] = -1;
    bool err = false;
    bool is_trans = false;
    auto setb = [&](bool t, int tmp_i, int tmp_j, bool b) {
        int i, j;
        if (t) { i = tmp_j; j = tmp_i; }
        else { i = tmp_i; j = tmp_j;}

        if (a[i][j] == !b)  err = true;
        else a[i][j] = b;
    };
    auto cntbit = [&](bool t, int i, bool b) -> int {
        int ans = 0;
        if (t) {
            rep(k,n) ans += (a[k][i] == b);
        } else {
            rep(k,n) ans += (a[i][k] == b);
        }
        return ans;
    };
    vector< vector<int> > cnf(2, vector<int>(n, -1)); // 行ごとの確定判定

    rep(i,2) rep(j,n) {
        // 論理積=1は1確定 論理和=0は0確定
        if (s[i][j] == u[i][j]) {
            cnf[i][j] = u[i][j];
            rep(k,n) setb(i, j, k, u[i][j]);
        }
        if (err) return false;
    }
    vector< vector<int> > yet(2);
    rep(i,2) rep(j,n) if (cnf[i][j] == -1) yet[i].push_back(j);

    rep(i,2) {
        if (yet[i].size() == 0) {   // 全確定済みは矛盾チェックして終了
            for (int idx : yet[!i]) {
                if (cntbit(!i, idx, u[!i][idx]) == 0) return false; // 論理和1(論理積0)は最低1つ1(0)がないとダメ
            }
            return true;
        } else if (yet[i].size() == 1) {    // 未確定1は矛盾のないように値をセットして終了
            int idx = yet[i][0];
            for (int idx2 : yet[!i]) {
                if (cntbit(!i, idx2, u[!i][idx2]) == 0) setb(i, idx, idx2, u[!i][idx2]); // 論理和1(論理積0)は最低1つ1(0)がないとダメ
                else setb(i, idx, idx2, u[i][idx]);
            }
            return (cntbit(i, idx, u[i][idx]) > 0);
        }
    }
    // タテヨコ共に2列以上未確定が残っているなら交互に1,0をセットすればよい
    rep(i,yet[0].size()) rep(j,yet[1].size()) setb(false, yet[0][i], yet[1][j], (i+j)%2);
    return true;
}

int main(int, char**)
{
    int n;
    cin >> n;

    vector< vector<bool> > s(2);
    vector< vector<bset> > bset_u(2);

    ull tmp;
    rep(i,2) rep(j,n) { cin >> tmp; s[i].push_back((tmp == 0) ? true : false); }
    rep(i,2) rep(j,n) { cin >> tmp; bset_u[i].push_back(bset(tmp)); }

    vector< vector<int> > a(n, vector<int>(n));
    vector< vector<bool> > u(2, vector<bool>(n));
    vector< vector<bset> > bset_a(n, vector<bset>(n));
    // ビット毎にチェック
    rep(b,64) {
        rep(i,2) rep(j,n) u[i][j] = bset_u[i][j].test(b);
        if (!make(s, u, a, n)) {
            cout << -1 << endl;
            return 0;
        }
        rep(i,n) rep(j,n) bset_a[i][j].set(b, a[i][j]);
    }

    rep(i,n) {
        rep(j,n) {
            if (j > 0) cout << " ";
            cout << bset_a[i][j].to_ullong();
        }
        cout << endl;
    }

    return 0;
}