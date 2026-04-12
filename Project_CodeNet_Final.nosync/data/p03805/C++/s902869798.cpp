#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define repo(i,o,n) for(int i=o;i<(int)(n);++i)
#define repm(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end());
#define vdelete(v) (v).erase(unique(all(v)), (v).end());
#define pb(n) push_back(n);
#define mp make_pair
#define MOD 1000000007
#define INF 9223372036854775807

int n,m,a,b,ans;
bool memo[8][8];
vector<int> v;

main() {
    cin >> n >> m;
    rep(i,m) {
        cin >> a >> b;
        a--,b--;
        memo[a][b] = memo[b][a] = true;
    }
    rep1(i,n-1) v.pb(i)
    do {
        int hoge = 0;
        rep(i,v.size()) {
            if (!memo[hoge][v[i]]) goto LoopBreak;
            hoge = v[i];
        }
        ans++;
        LoopBreak:;
    } while(next_permutation(all(v)));
    cout << ans << endl;
}


