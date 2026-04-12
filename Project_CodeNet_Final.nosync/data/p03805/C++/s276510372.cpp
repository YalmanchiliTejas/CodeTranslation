#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n, m;
    cin >> n >> m;
    bool g[10][10];
    rep(i, 10) rep(j, 10) g[i][j] = false;
    rep(i, m) {
        int a,b;
        cin >> a >> b;
        --a, --b;
        g[a][b] = g[b][a] = true;
    }
    vector<int> v(n);
    rep(i, n) v[i] = i;
    int ans = 0;
    do {
        bool c = true;
        rep(i, n-1) c = c && g[v[i]][v[i+1]];
        ans += c;
    } while(next_permutation(v.begin()+1, v.end()));
    cout << ans << endl;
    return 0;
}
