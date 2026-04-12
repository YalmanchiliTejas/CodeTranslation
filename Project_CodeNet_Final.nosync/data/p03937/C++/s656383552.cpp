#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR0(A,n) { cout << #A << " = "; FORN(_,n) cout << A[_] << ' '; cout << endl; }

#define MOD 1000000007
#define INF 2000000000

int GLL(LL& x) {
    return scanf("%lld", &x);
}

int GI(int& x) {
    return scanf("%d", &x);
}

int h, w;

vector<string> board; string row;

int main() {
    GI(h); GI(w);

    FOR1(i, h) {
        cin >> row;
        board.PB(row);
    }

    int x = 0, y = 0;

    while ((x != h - 1 || y != w - 1) && board[x][y] == '#') {
        bool okr = (y + 1 < w && board[x][y + 1] == '#');
        bool okd = (x + 1 < h && board[x + 1][y] == '#');

        if (okr + okd != 1) {
            printf("Impossible\n");
            return 0;
        }
        else if (okr) {
            board[x][y] = 'O';
            y++;
        }
        else {
            board[x][y] = 'O';
            x++;
        }
    }

    board[h-1][w-1] = 'O';

    FORN(i, h) FORN(j, w) {
        if (board[i][j] == '#') {
            printf("Impossible\n");
            return 0;
        }
    }

    printf("Possible\n");
    return 0;
}
