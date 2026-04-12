#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const ll INF = 1<<21;
// static const ll MOD = 1e9 + 7;

bool compPair(const pair<int, int>& arg1, const pair<int, int>& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }


int main(void) {
    int h,w;
    cin >> h >> w;

    vector<vector<char>> a(h, vector<char>(w, 0));
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            cin >> a.at(ih).at(iw);
        }
    }

    vector<int> hskip;
    vector<int> wskip;
    bool flg;
    for(int ih=0;ih<h;ih++) {
        flg = true;
        for(int iw=0;iw<w;iw++) {
            if(a.at(ih).at(iw)=='#') { 
                flg = false;
                break;
            }
        }
        if(flg) hskip.push_back(ih);
    }
    for(int iw=0;iw<w;iw++) {
        flg = true;
        for(int ih=0;ih<h;ih++) {
            if(a.at(ih).at(iw)=='#') { 
                flg = false;
                break;
            }
        }
        if(flg) wskip.push_back(iw);
    }

    bool flgrt;
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            flg = true;
            flgrt = true;
            for(auto jh:hskip) {
                if(ih==jh) { 
                    flg=false;
                    flgrt = false;
                }
            }
            for(auto jw:wskip) {
                if(iw==jw) flg=false;
            }
            if(flg) cout << a.at(ih).at(iw);
        }
        if(flgrt) cout << endl;
    }

    return 0;
}
