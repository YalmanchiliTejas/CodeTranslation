#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define Sort(Array) sort(Array.begin(), Array.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define out(ans) cout << ans << endl;
const int MOD = 1000000007;
const int INF = 2147483647;
const ld PI = 3.14159265358979323846;

//------------↓------------- M -------------- E ---------------- M --------------- O ---------------↓--------------//
// コンパイル 
// g++ -std=c++1z
//
// -------型変換--------
// int を string に変換
// string s = to_string(n);
// string を int に変換
// int n = stoi(s);
//
// -------二分探索---------
// k以上の値が最初に現れる時のイテレータ
// lower_bound(data.begin(), data.end(), k)
// kより大きい値が最初の現れる時のイテレータ O(logN)
// upper_bound(data.begin(), data.end(), k)
// kがdataに存在するかをtrue or falseで返す O(logN)
// binary_search(data.begin(), data.end(), k)
// 
//
//
//
//
//
// 
//------------↑------------- M -------------- E ---------------- M --------------- O ---------------↑--------------//







int main(void) {

    int n; cin >> n;
    vector <string> S(n);
    rep(i,n) cin >> S[i];
    int cnt[n]['z' - 'a' + 1];
    rep(i,n){
        rep(j, 'z' - 'a' + 1) {
            cnt[i][j] = 0;
        }
    }
    rep(i,n) {
        rep(j,S[i].size()) {
            int c = S[i][j] - 'a';
            ++cnt[i][c];
        }
    }
    int mn['z' - 'a' + 1];
    rep(i, 'z' - 'a' + 1) mn[i] = 0;
    rep(j, 'z' - 'a' + 1) {
        int c_min = INF;
        rep(i,n) {
            c_min = min(c_min, cnt[i][j]);
        }
        mn[j] = c_min;
    }
    rep(i,'z' - 'a' + 1) {
        char c = 'a' + i;
        rep(j,mn[i]) {
            cout << c;
        }
    }
    cout << endl;
    

    return 0;
}









