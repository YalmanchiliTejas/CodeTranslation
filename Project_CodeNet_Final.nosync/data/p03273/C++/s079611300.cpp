#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define ANS(n) cout << (n) << endl
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)
#define mp make_pair

int main()
{
    int32 h,w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    REP(i,h)REP(j,w)cin >> a[i][j];
    REP(i,h){
        bool flg = true;
        REP(j,w){
            if(a[i][j] == '#'){
                flg = false;
                break;
            }
        }
        if(flg){
            a.erase(a.begin() + i);
            i--;
            h--;
        }
    }
    REP(j,w){
        bool flg = true;
        REP(i,h){
            if(a[i][j] == '#'){
                flg = false;
                break;
            }
        }
        if(flg){
            REP(i,h){
                a[i].erase(a[i].begin() + j);
            }
            j--;
            w--;
        }
    }
    REP(i,h){
        REP(j,w){
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}