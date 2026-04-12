#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(x) x.begin(), x.end()
#define sorn(i, n) char((i == n-1)?'\n':' ')
using namespace std;

constexpr int LEN = 10;
bool g[LEN][LEN];
bool vis[LEN];

bool check(const vector<int>& s, const int n){
    rep(i, n-1) if(!g[s[i]][s[i+1]]) return false;
    return true;
}

int main(){
    memset(g, 0, sizeof(g));
    int n, m; cin >> n >> m;
    rep(i, m) {
        int a, b; cin >> a >> b;
        g[--a][--b] = true;
        g[b][a] = true;
    }

    vector<int> s;
    rep(i, n) s.push_back(i);
    int ans = 0;
    do{
        if(check(s, n)) ans++;
    } while(next_permutation(s.begin()+1, s.end()));
    cout << ans << endl;

    return 0;
}