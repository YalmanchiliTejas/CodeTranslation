#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define For(i,a,b) for(int (i)=(a); (i)<(b); (i)++)


typedef pair<int, int> P;

int h, w;
vector<vector<char>> v;

const P NOT_FOUND = make_pair(-1,-1);

int main() {
    
    cin >> h >> w;
    v = vector<vector<char>>(h, vector<char>(w));
    
    REP(i,h) {
        REP(j,w) {
            char c;
            cin >> c;
            v[i][j] = c;
        }
    }
    
    int x = 0;
    int y = 0;
    
    bool poss = false;
    int cnt = 1;
    while (true) {
        if (x+1 < h && v[x+1][y] == '#') {
            x++;
        }else if (y+1 < w && v[x][y+1] == '#') {
            y++;
        }else {
            break;
        }
        cnt++;
        
        if (x == h-1 && y == w-1) {
            poss = true;
            break;
        }
    }
    
    int cntall = 0;
    REP(i,h) {
        REP(j,w) {
            if (v[i][j] == '#') {
                cntall++;
            }
        }
    }
    
    if (poss && cnt == cntall) {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Impossible" << endl;
    return 0;
}