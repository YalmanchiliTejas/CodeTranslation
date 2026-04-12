#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int H, W;
    cin >> H >> W;
    vector<string>HWs(H);
    for (int i=0; i<H; i++){
        cin >> HWs[i];
    }

    vector<bool>rows(H);
    vector<bool>columns(W);

    string dots;
    for(int i=0;i<W; i++) dots += '.';
    

    for (int i=0; i<H; i++){
        if (HWs[i] == dots)rows[i] = false;
        else rows[i] = true;
    }

    dots = "";
    for(int i=0; i<H; i++) dots += '.';

    for (int i=0; i<W; i++){
        string row;
        for (int j=0; j<H; j++) row += HWs[j][i];

        if (row == dots)columns[i] = false;
        else columns[i] = true;
    }

    for (int i=0; i<H; i++){
        bool w = false;
        for (int j=0; j<W; j++){
            if (rows[i] && columns[j]){ cout << HWs[i][j]; w=true;}
        }
        if (w)cout << endl;
    }
}