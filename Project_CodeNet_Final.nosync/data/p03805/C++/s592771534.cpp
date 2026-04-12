#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rep1(i, n) FOR(i, 1, n+1)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define rwhole(x) (x).rbegin(), (x).rend()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define P pair<int, int>
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

bool to[10][10];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a][b] = true;
        to[b][a] = true;
    }
    vector<int> v;
    rep(i, n) {
        v.push_back(i);
    }
    int ans = 0;
    do {
        if (v[0]!=0) continue;
        bool ok = true;
        rep(i, n-1) {
            if (!to[v[i]][v[i+1]]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    } while (next_permutation(whole(v)));

    
    cout << ans << endl;
    return 0;
}
