// https://atcoder.jp/contests/abc107/tasks/abc107_b
// B - Grid Compression

#include<bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector <string> a(H);
    vector <bool> del(W);
    int rm=0;
    for (int i=0; i<H; i++) cin >> a.at(i);
    for (int i=0; i<W; i++) del.at(i)=false;
    for (int j=0; j<W; j++) {
        bool remcol=true;
        for (int i=0; i<H; i++) {
            if (a.at(i).at(j)!='.') {
                remcol = false;
                break;
            }
        }
        if (remcol) {
            del.at(j)=true;
            rm++;
        }
    }
    for (int j=W-1; j>=0; j--) {
        if (del.at(j)) {
            for (int i=0; i<H; i++) a.at(i).erase(a.at(i).begin()+j);
        }
    }
    for (int i=0; i<H; i++) {
        for (int j=0; j<W-rm; j++) {
            if (a.at(i).at(j)!='.') {
                cout << a.at(i) + "\n";
                break;
            }
        }
    }
}