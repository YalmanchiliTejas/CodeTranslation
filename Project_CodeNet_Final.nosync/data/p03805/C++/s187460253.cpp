#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define REP2(i,s,e) for(int i=(int)(s);i<(int)(e);++i)
#define RREP(i,s,e) for(int i=(int)(s-1);i>=(int)(e);--i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin(),ie=(c).end();i!=ie;++i)
#define ALL(c) (c).begin(), (c).end()

int main() {
    int n,m;cin>>n>>m;
    bool e[n][n];
    fill(e[0], e[n], false);
    REP(i, m) {
        int a,b;cin>>a>>b;
        a--;b--;
        e[a][b] = e[b][a] = true;
    }

    vector<int> v;
    REP2(i, 1, n) v.push_back(i);

    int ans = 0;

    do {
        int node = 0;
        bool f = true;
        FOR(i, v) {
            f &= e[node][*i];
            node = *i;
        }

        if (f) ans++;
    } while( next_permutation(ALL(v)) );

    cout << ans << endl;
}
