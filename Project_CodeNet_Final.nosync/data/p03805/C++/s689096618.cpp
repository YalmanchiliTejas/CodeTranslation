#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <cstring>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define vi vector < int >
#define vll vector < long long >
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))
#define fname "searching"

const int inf = (int)1e9;
const ll INF = (ll)1e18;
const double eps = 1e-9;
const double pi = acos(-1.0);
const int mod = (int)1e9 + 7;

int n, m;
vi v[100];
int u[10];
int ans;

void dfs(int cur, int l = 0){
    u[cur] = 1;
    int cnt = 0;
    for(int i = 0; i < sz(v[cur]); ++i){
        int to = v[cur][i];
        if(!u[to]){
            dfs(to, l + 1);
            cnt++;
        }
    }
    if(cnt == 0 && l + 1 == n) ans++;
    u[cur] = 0;
}

int solve(){
    cin >> n >> m;
    for(int i = 0, x, y; i < m; ++i){
        cin >> x >> y;
        --x, --y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(0);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << solve() << "\n";
    
    return 0;
}
