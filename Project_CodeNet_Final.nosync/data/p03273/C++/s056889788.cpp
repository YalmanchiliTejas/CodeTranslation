#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef long long ll;

int main(){
    int h, w;
    cin >> h >> w;
    string grid[100];
    REP(i, h){
        cin >> grid[i];
    }

    vector<int> keeprow(h, 0);
    vector<int> keepcol(w, 0);

    REP(i, h){
        REP(j, w){
            if (grid[i][j] == '#'){
                keeprow[i] = 1;
                keepcol[j] = 1;
            }
        }
    }

    REP(i, h){
        REP(j, w){
            if (keeprow[i] == 1  && keepcol[j] == 1){
                cout << grid[i][j];
            }
        }
        if (keeprow[i] == 1) cout << endl;
    }



}