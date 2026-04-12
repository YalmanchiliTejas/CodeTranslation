#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<int> to[10];
int ans = 0;
int n,m;
void solve(int now, int cnt, int p, vector<bool> v){
    if(cnt == n) ans++;
    else{
        for(auto u : to[now]){
            if(u != p && v[u] == 0){
                v[u] = 1;
                solve(u, cnt+1, now, v);
                v[u] = 0;
            }
        }
    }
}
int main(){
    cout << fixed << setprecision(10);
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    vector<bool> v(n,0);
    v[0] = 1;
    solve(0, 1, -1, v);
    cout << ans << endl;
    return 0;
}