#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    REP(i, h) cin >> a[i];
    map<int, bool> mp1, mp2;
    REP(i, h){
        bool flag = true;
        REP(j, w) if(a[i][j] == '#') flag = false;
        if(flag) mp1[i] = true;
    }
    REP(j, w){
        bool flag = true;
        REP(i, h) if(a[i][j] == '#') flag = false;
        if(flag) mp2[j] = true;
    }

    REP(i, h){
        REP(j, w){
            if(!mp1[i] && !mp2[j]) cout << a[i][j];
        }
        if(!mp1[i])cout << endl;
    }
}
