#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define maxs(x,y) x = max(x, y)
#define mins(x,y) x = min(x, y)
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    int H, W;
    cin >> H >> W;
    
    char a[H][W];
    bool yoko[H];
    bool tate[H];

    REP(i, H) {
        REP(j, W) {
            cin >> a[i][j];
        }
    }

    REP(i, H) {
        bool tmp = false;
        REP(j, W) {
            if (a[i][j] == '#') 
                tmp = true;
        }
        yoko[i] = tmp;
    }
    REP(i, W) {
        bool tmp = false;
        REP(j, H) {
            if (a[j][i] == '#') 
                tmp = true;
        }
        tate[i] = tmp;
    }
    
    REP(i, H) {
        REP(j, W) {
            if (yoko[i] && tate[j])
            cout << a[i][j];
        }
        cout << endl;
    }





    return 0;
}