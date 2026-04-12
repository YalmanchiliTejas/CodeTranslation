#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

VI e[10];
int ans;

void dfs(int now, VI a){
    int n = a.size();
    int x = 0;
    REP(i,n) x += a[i];
    if (x == n){
        ans++;
        return;
    }
    REP(i,e[now].size()){
        int next = e[now][i];
        if (a[next]) continue;
        a[next] = 1;
        dfs(next, a);
        a[next] = 0;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    while (m--){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    VI a(n);
    a[0] = 1;
    dfs(0, a);

    cout << ans << endl;



    return 0;
}