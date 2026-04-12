#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

using Gragh = vector<vector<int>>;

int main() {
    int n, m;
    cin >> n >> m;
    Gragh to(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<int> order(n);
    rep(i, n) order[i] = i;

    int ans = 0;
    do {
        if(order[0] != 0) continue;
        bool check;
        int cnt = 0;
        rep(i, n - 1) {
            check = true;
            for(auto x : to[order[i]]) {
                if(x == order[i + 1]) check = false;
            }
            if(check) break;
            cnt++;
        }
        if(cnt == n - 1) ans++;
    } while(next_permutation(ALL(order)));

    cout << ans << endl;

    return 0;
}