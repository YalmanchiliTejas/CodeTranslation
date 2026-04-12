#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define FOR(i,a,b)  for(ll (i)=a;(i)<(b);++(i))
#define RFOR(i,a,b) for(ll (i)=a;(i)>=(b);--(i))
#define REP(i,n)    FOR(i,0,n)
#define RREP(i,n)   RFOR(i,n,0)
#define ALL(v)      (v).begin(),(v).end()
#define BIT(n)      (1LL<<(n))
#define IN(x,l,r)   ((l)<=(x)&&(x)<=(r))
#define SHOW(x)     cout<<#x<<" = "<<x<<endl
#define SORT(v)     sort(ALL(v))
#define SZ(v)       (ll)(v).size()
#define UNIQ(v)     SORT(v);(v).erase(unique(ALL(v)),(v).end())
#define PERM(v)     for(bool p=1;p;p=next_permutation(ALL(v)))
#define PQ(T)       priority_queue<T,vector<T>,greater<T>>

template<typename T>string join(const vector<T>& v, string d=" ")
{stringstream s;REP(i,SZ(v))s<<d<<v[i];return s.str().substr(d.length());}

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v)
{if(SZ(v))s<<join(v,", ");return s;}

const ll INF = 1e15;
const ll MOD = 1e9+7;
const double EPS = 1e-10;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
    ll H, W; cin >> H >> W;
    vector<string> field(H); REP(i, H) cin >> field[i];
    
    ll total = 0;
    REP(i, H) REP(j, W) if (field[i][j] == '#') total++;
    
    ll x = 0;
    ll y = 0;
    ll visit = 0;
    while (true) {
        visit++;
        
        if (field[y][x] != '#') {
            cout << "Impossible" << endl;
            return 0;
        }
        
        ll cnt = 0;
        if (x + 1 < W and field[y][x+1] == '#') cnt++;
        if (y + 1 < H and field[y+1][x] == '#') cnt++;
        
        if (cnt != 1) {
            cout << "Impossible" << endl;
            return 0;
        }
        
        if (x + 1 < W and field[y][x+1] == '#') x++;
        else if (y + 1 < H and field[y+1][x] == '#') y++;
        
        if (x == W - 1 and y == H - 1) {
            if (visit + 1 == total) cout << "Possible" << endl;
            else cout << "Impossible" << endl;
            return 0;
        }
    }
    
    return 0;
}
