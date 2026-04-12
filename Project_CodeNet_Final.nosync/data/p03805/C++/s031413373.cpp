#include<bits/stdc++.h>
using namespace std;

#define lint long long
#define P pair<int, int>
#define LLP pair<long long, long long>
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int n, m;
vector< vector<int> > g;
int ans = 0;

void dfs(int now, vector<bool> done){
    done[now] = true;
    for(auto x : g[now]){
        if(!done[x]){
            dfs(x, done);
        }
    }
    bool flag = true;
    rep(i, n){
        flag &= done[i];
    }
    if(flag){
        ++ans;
    }
    return;
}

int main(){
    cin >> n >> m;
    g.resize(n);
    rep(i, m){
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<bool> done(n);
    dfs(0, done);
    cout << ans << endl;
    return 0;
}