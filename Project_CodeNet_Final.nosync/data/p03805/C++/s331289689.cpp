#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
using namespace std;
typedef pair<int, int> P;

int n, m;
bool G[10][10];

signed main(){
    cin >> n >> m;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a][b] = true;
        G[b][a] = true;
    }
    vector<int> d(n);
    rep(i, 0, n) d[i] = i;
    int ans = 0;
    do{
        if(d[0] != 0) continue;
        bool f = true;
        rep(i, 1, n){
            if(G[d[i - 1]][d[i]] == false) f = false;
        }
        if(f) ans++;
    }while(next_permutation(all(d)));
    cout << ans << endl;
}