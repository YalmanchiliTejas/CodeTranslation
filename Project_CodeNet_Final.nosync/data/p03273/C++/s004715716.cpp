#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#define REP(i,n) for (int i=0;i<(n);i++)
using namespace std;

int main(){
    int h, w;
    char G[105][105];
    cin >> h >> w;
    vector<bool>row(h, false);
    vector<bool>col(w, false);
    REP(i, h){
        REP(j, w){
            cin >> G[i][j];
            if(G[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    REP(i, h){
        if(row[i]){
            REP(j, w){
                if(col[j]){
                    cout << G[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}

