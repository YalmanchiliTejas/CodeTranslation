#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

bool tassei = false;
int kosu = 0;
int h, w;
string s[8];

void dfs(P ichi, int now_kosu) {
    if(now_kosu == kosu){
        if(ichi.first == h-1 && ichi.second == w-1) {
         tassei = true;
        }
        return;
    } else {
        if(ichi.first < h - 1) {
            /* 下に行く */
            if(s[ichi.first+1][ichi.second] == '#') {
                ichi.first++;
                dfs(ichi, now_kosu+1);
            }
        }
        if(ichi.second < w - 1) {
            /* 右に行く */
            if(s[ichi.first][ichi.second+1] == '#') {
                ichi.second++;
                dfs(ichi, now_kosu+1);
            }
        }
    }
}

int main(){
    cin >> h >> w;
    REP(i, h) cin >> s[i];

    REP(i, h) REP(j, w) {
        if(s[i][j] == '#') kosu++;
    }

    P start;
    start.first = start.second = 0;

    dfs(start, 1);

    if(tassei) cout << "Possible" << endl;
    else cout << "Impossible" << endl;

    return 0;
}