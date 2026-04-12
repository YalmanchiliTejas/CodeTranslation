#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
    int h,w;
    cin >> h >> w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<char> row(w,'.');
    vector<char> row2(w,'x');
    REP(i,h){
        REP(j,w){
            cin >> a.at(i).at(j);
        }
        if(a.at(i) == row){
            a.at(i) = row2;
        }
    }
    REP(j,w){
        bool flag = true;
        REP(i,h){
            if(a.at(i).at(j) == '#')flag = false;
        }
        if(flag){
            REP(i,h)a.at(i).at(j) = 'x';
        }
    }
    REP(i,h){
        bool flag = false;
        REP(j,w){
            char out = a.at(i).at(j);
            if(out != 'x'){
                flag = true;
                cout << out;
            }
        }
        if(flag)cout << endl;
    }
}
