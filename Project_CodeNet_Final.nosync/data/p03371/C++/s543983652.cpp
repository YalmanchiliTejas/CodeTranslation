#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
#define REP(i, n) for(int i=0; i<n; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
using P = pair<int, int>;
const int inf = 1e9;
const ll INF = 1e18;
const ll mod = 1e9+7;

struct edge{
    int to;
    int cost;
};
using graph = vector<vector<edge>>;

int main(){
    int a, b, c, x, y; cin >> a >> b >> c >> x >> y;
    int ans = inf;
    for(int i=0; i<=max(x,y)*2; i+=2){
        ans = min(ans, c*i+max(0, x-i/2)*a+max(0, y-i/2)*b);
    }
    cout << ans << endl;
    return 0;
}