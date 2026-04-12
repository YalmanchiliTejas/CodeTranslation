#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;


int main(){
    int H, W;
    cin >> H >> W;
    char a[110][110];
    REP(i,H){
        REP(j,W){
            cin >> a[i][j];
        }
    }
    bool row[H];
    bool column[W];
    REP(i,H){
        row[i] = true;
        REP(j,W){
            if (a[i][j] == '#') row[i] = false;
        }
    }
    REP(i,W){
        column[i] = true;
        REP(j,H){
            if(a[j][i] == '#') column[i] = false;
        }
    }
    REP(i,H){
        if(row[i]) continue;
        REP(j,W){
            if(!column[j]) cout << a[i][j];
        }
        cout << endl;
    }
}