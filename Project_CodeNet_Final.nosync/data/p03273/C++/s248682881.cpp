#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
template<class T> inline void chmin(T& a, T b) {if (a>b) a=b; }
template<class T> inline void chmax(T& a, T b) {if (a<b) a=b; }
inline void print() { cout << endl; }
template <class Head, class... Tail> inline void print(Head&& head, Tail&&... tail) {cout << head; if (sizeof...(tail) != 0) cout << " "; print(forward<Tail>(tail)...);}
template <class T> inline void print(vector<T>& vec) { for (auto& a : vec) {cout << a; if (&a != &vec.back()) cout << " "; } cout << endl;}
template <class T> inline void print(vector<vector<T>>& df) { for (auto& vec : df) { print(vec); }}
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;


int main() { 
    int H, W; cin >> H >> W;
    vector<vector<char>> m;
    m.resize(H);
    REP(i, H) {
        m[i].resize(W);
        REP(j, W) {
            cin >> m[i][j];
        }
    }

    vector<bool> row(H, false);
    vector<bool> col(W, false);
    REP(h, H) {
        REP(w, W) {
            if(m[h][w] == '#') {
                row[h] = true;
                col[w] = true;
            }
        }
    }

    REP(h, H) {
        if(row[h]) {
            bool show = false;
            REP(w, W) {
                if(col[w]) {
                    cout << m[h][w];
                    show = true;
                }
            }
            if(show) cout << endl;
        }
    }


    // vector<int> mh;
    // vector<int> mw;
    // REP(w, W) {
    //     bool allWhite = true;
    //     REP(h, H) {
    //         if(m[h][w] != '.') {
    //             allWhite = false;
    //         }
    //     }
    //     if (allWhite) {
    //         mw.push_back(w);
    //     }
    // }
    // REP(h, H) {
    //     bool allWhite = true;
    //     REP(w, W) {
    //         if(m[h][w] != '.') {
    //             allWhite = false;
    //         }
    //     }
    //     if (allWhite) {
    //         mh.push_back(h);
    //     }
    // }
    // vector<vector<char>> comp;
    // REP(h, H) {
    //     comp.resize(comp.size()+1);
    //     REP(w, W) {
    //         if(find(mh.begin(), mh.end(), h) == mh.end()) {
    //             if(find(mw.begin(), mw.end(), w) == mw.end()) {
    //                 int hh = comp.size()-1;
    //                 int ww = comp[hh].size();
    //                 // print(hh, ww);
    //                 // print(h, w, m[h][w]);
    //                 comp[hh].resize(comp[hh].size()+1);
    //                 comp[hh][ww] = m[h][w];
    //             }
    //         }
    //     }
    // }
    // REP(h, comp.size()) {
    //     REP(w, comp[h].size()) {
    //         cout << comp[h][w];
    //     }
    //     if(comp[h].size() > 0) cout << endl;
    // }

    
    return 0;
}