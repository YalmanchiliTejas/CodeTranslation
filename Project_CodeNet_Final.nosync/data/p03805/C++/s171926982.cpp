#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(10, vector<int>(10, 0));
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        graph[x-1][y-1] = graph[y-1][x-1] = 1;
    }

    vector<int> s(n);
    rep(i,n){
        s[i] = i; 
    }

    int ans = 0;
    do {
        if(s[0]!=0) break;                    //スタートが1以外は無視
        rep(i, n-1) {                         //全ての辺（n-1）の繋がりがあるか
            if(graph[s[i]][s[i+1]]==0) break;
            if(i == n-2) ans++;
        }
    } while (next_permutation(s.begin(), s.end()));


    cout << ans << endl;
    
    return 0;
}