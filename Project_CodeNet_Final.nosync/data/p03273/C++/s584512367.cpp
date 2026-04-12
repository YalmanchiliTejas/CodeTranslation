#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
//#define int long long

signed main(){
    int h, w;
    cin >> h >> w;
    vector<vector<char>> field(h, vector<char>(w));
    rep(i,h)rep(j,w) cin >> field[i][j];
    vector<int> print_row, print_column;
    
    rep(i,h){
        bool ignore = true;
        rep(j,w){
            if(field[i][j]=='#'){
                ignore = false;
                break;
            }
        }
        if(ignore) continue;
        print_column.emplace_back(i);
    }
    
    rep(i,w){
        bool ignore = true;
        rep(j,h){
            if(field[j][i]=='#'){
                ignore = false;
                break;
            }
        }
        if(ignore) continue;
        print_row.emplace_back(i);
    }
    
    for(int i : print_column){
        for(int j : print_row){
            cout << field[i][j];
        }
        cout << endl;
    }
}