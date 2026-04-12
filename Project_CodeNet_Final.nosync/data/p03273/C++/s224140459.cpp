#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define sc(x) scanf("%d",&x);
int main(){
    int h, w;
    bool check;
    sc(h) sc(w)
    vector<vector<char> > G(h, vector<char>(w));
    vector<bool> row(h, false), col(w, false);
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) cin >> G[i][j];
    }
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (G[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) if (row[i] && col[j]) cout << G[i][j];
        if (row[i]) cout << endl;
    }
    return 0;
}