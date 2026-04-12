#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int> > v(100000);
    vector<int> deg(n,0);
    bool seen[n];
    memset(seen,0,sizeof(seen));
    for (int i = 1; i < n ; ++i) {
        int a, b; 
        cin >> a >> b; --a, --b;
        v[a].push_back(b);
        v[b].push_back(a);
        deg[a]++, deg[b]++;
    }
    bool res = true;
    queue<int> que;
    for (int i = 0; i < n; ++i) if (deg[i] == 1) que.push(i);
    while (!que.empty()){
        int now = que.front(); que.pop();
        if(seen[now]) continue;
        seen[now] = true;

        int nv = -1;
        for (auto e:v[now])if(!seen[e]) nv = e;
        if (nv == -1){
            res = false;
            break;
        }
        seen[nv] = true;
        for (auto v2 : v[nv]) {
            if (seen[v2]) continue;
            deg[v2]--;
            if (deg[v2] == 1) que.push(v2);
        }
    }
    if (res) cout << "Second" << endl;
    else cout << "First" << endl;
    return 0;
}
