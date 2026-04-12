#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define PUSH(n,v) for(int i=0; i<(n); i++) {int j; cin >> j; v.push_back(j);}
#define ALL(v) v.begin(), v.end()
#define print(s) cout << (s) << endl

int bdsize;

bool hasBlank(vector<vector<int>> bd) {
    REP(i,bdsize) {
        REP(j, bdsize) {
            if (bd[i][j] == 0) return true;
        }
    }
    return false;
}

int nextInt;

void fillNext(vector<vector<int>> &bd, int x, int y) {
    if (!hasBlank(bd)) return;
    if (x >= bdsize) {fillNext(bd, 0, y); return;}
    if (y >= bdsize) {fillNext(bd, x, 0); return;}
    if (y < 0) {fillNext(bd, x, bdsize-1); return;}
    if (bd[x][y] != 0) {fillNext(bd, x+1, y-1); return;}
    bd[x][y] = nextInt;
    nextInt++;
    fillNext(bd, x+1, y+1);
}

void solve78(int n) {
    bdsize = n;
    vector<vector<int>> bd;
    REP(i,n) {
        vector<int> sub;
        REP(j,n) sub.push_back(0);
        bd.push_back(sub);
    }
    int lastx = n/2 + 1;
    int lasty = n/2;
    bd[lastx][lasty] = 1;
    nextInt = 2;
    fillNext(bd, lastx+1, lasty+1);
    REP(i,n) {
        REP(j,n) {
            printf("%4d", bd[i][j]);
        }
        cout << endl;
    }
}

int main() {
    int n;
    while (cin >> n, n) {
        solve78(n);
    }
    return 0;
}