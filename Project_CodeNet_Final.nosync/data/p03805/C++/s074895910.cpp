#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
ll mod_pow(ll, ll, ll);
ll mod_fact(ll, ll);
ll mod_inv(ll, ll);
//
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> graph(n, vector<bool>(n));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x - 1][y - 1] = true;
        graph[y - 1][x - 1] = true;
    }
    vector<int> a;
    for(int i = 0; i < n; i++) a.push_back(i);
    int ans = 0;
    do{
        if(a[0]) break;
        bool pos = true;
        for(int i = 0; i < n - 1; i++){
            pos &= graph[a[i]][a[i + 1]];
        }
        if(pos) ans++;
    }while(next_permutation(a.begin(), a.end()));
    cout << ans;
}