#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;
const ll MOD = 1e9 + 7;



int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int ans = INF;
    rep(i, max(x, y) + 1){
        int cost = a*max(0, x-i) + b*max(0, y-i) + 2*c*i;
        chmin(ans, cost);
    }

    cout << ans << endl;
}