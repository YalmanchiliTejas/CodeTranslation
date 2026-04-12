#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<set<int> > G(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].insert(b);
        G[b].insert(a);
    }

    vi rem(N), lev(N);
    queue<int> q;
    rep(i, N)if (sz(G[i]) == 1)lev[*G[i].begin()] = 1;
    rep(i, N)if (lev[i])q.push(i);

    while (sz(q)) {
        int u = q.front(), flag=0; q.pop();
        each(v, G[u]) {
            if (sz(G[v]) == 1 && !flag++) {
                rem[v] = 1;
            }
            G[v].erase(u);
            if (sz(G[v]) == 1) {
                int w = *G[v].begin();
                q.push(w);
            }
        }
        rem[u] = 1;
    }

    rep(i, N)if (!rem[i] && sz(G[i]) == 0) {
        cout << "First" << endl;
        return 0;
    }
    cout << "Second" << endl;
}
