#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
const ll INF = 1e10;

int main() {
    int n,m; cin >> n >> m;
    vector<vector<int>> dist(n,vector<int>(n,1));
    for (int i = 0; i < m; i ++) {
        int a,b; cin >> a >> b;
        a --; b --;
        dist[a][b] = 0;
        dist[b][a] = 0;
    }
    
    vector<int> list(n - 1);
    for (int i = 0 ; i < n - 1; i ++) {
        list[i] = i + 1;
    }
    
    int cnt = 0;
    do {
        bool flag = true;
        if (dist[0][list[0]]) continue;
        for (int i = 0; i < n - 2; i ++) {
            if (dist[list[i]][list[i + 1]]) {
                flag = false;
                break;
            }
        }
        if (flag) cnt ++;

    }while(next_permutation(list.begin(),list.end()));

    cout << cnt << endl;
}

