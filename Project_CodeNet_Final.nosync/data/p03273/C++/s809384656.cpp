//自称高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
    int ans = 0;
    int tmp;
    int h, w;
    cin >> h >> w;
    vector<string> a(h );
    REP(i, h) cin >> a[i];
    bool white;
    REP(i, h){
        white = true;
        REP(j, w) {
            if(a[i][j] == '#') white = false;
        }
        if(white){
            REP(j, w) a[i][j] = '*';
        }
    }
    REP(j, w){
        white = true;
        REP(i, h) {
            if(a[i][j] == '#') white = false;
        }
        if(white){
            REP(i, h) a[i][j] = '*';
        }
    }
    REP(i, h){
        white = true;
        REP(j, w) {
            if(a[i][j] != '*') {
                cout << a[i][j];
                white = false;
            }
        }
        if(!white) cout << endl;
    }
    //cout << ans << endl;
}