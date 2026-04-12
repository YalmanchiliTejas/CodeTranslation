#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
#define all(a) a.begin(), a.end()

const int MOD = 1e9+7;
const int INF = 1001001001;
int edge[8][8] {0};

int main(){
    int N, M;
    cin >> N >> M;
    rep(i, 0, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    int ans = 0;
    vector<int> v(N);
    iota(v.begin(), v.end(), 0);
    do {
        bool ok = true;
        if (v[0] != 0) continue;
        rep(i, 1, N){
            if (edge[v[i-1]][v[i]]) continue;
            ok = false;
            break;
        }
        if (ok){
            ans++;
        }
    } while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}