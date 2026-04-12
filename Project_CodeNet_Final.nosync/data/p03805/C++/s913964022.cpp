#include <bits/stdc++.h>

using namespace std;

const int N = 10;
int n, m, edge[N][N];
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a >> b;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }

    int cnt = 0;
    for(int i = 2; i <= n; i++){
        a.push_back(i);
    }
    do {
        int cur = 1;
        bool can = true;
        for(auto x : a){
            if(!edge[cur][x]){
                can = false;
            }
            cur = x;
        }
        if(can){
            cnt++;
        }
    } while(next_permutation(a.begin(), a.end()));
    cout << cnt << '\n';
    return 0;
}