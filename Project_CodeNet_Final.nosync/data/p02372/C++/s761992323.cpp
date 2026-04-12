#include <bits/stdc++.h>
using namespace std;

#define MAX_N 10000

typedef pair<int, int> P;

int n;
vector<P> E[MAX_N];
vector<int> dp[MAX_N];

int height(int v, int e){
    if(dp[v][e] != -1) return dp[v][e];
    int ans = 0, u = E[v][e].first, w = E[v][e].second;
    if(E[u].size() == 1) return dp[v][e] = w;
    for(int i = 0; i < E[u].size(); i++){
        if(E[u][i].first == v) continue;
        ans = max(ans, height(u, i));
    }
    return dp[v][e] = w + ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int s, t, w;
        cin >> s >> t >> w;
        E[s].push_back(P(t, w));
        E[t].push_back(P(s, w));
    }
    for(int i = 0; i < n; i++)
        dp[i].resize(E[i].size(), -1);
    for(int i = 0; i < n; i++){
        int H = 0;
        for(int j = 0; j < dp[i].size(); j++)
            H = max(H, height(i, j));
        cout << H << endl;
    }
    
    return 0;
}
