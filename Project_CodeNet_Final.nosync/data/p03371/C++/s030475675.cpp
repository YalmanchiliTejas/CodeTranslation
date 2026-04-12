#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
const int INF = 1001001001;


int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int x, y;
    cin >> x >> y;
    int ans = INF;
    
    int z = 0;
    while (max(x, y)>=0) {
        chmin(ans, a*max(x, 0)+b*max(y, 0)+c*z);
        x--; y--; z+=2;
    }
    
    cout << ans << endl;
    return 0;
}
