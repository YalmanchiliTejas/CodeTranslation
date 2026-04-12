#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int g_e, g_v;
bool visited[8];

int dfs(int now, int &ans, vector<vector<int>> &c, stack<int> &st){
    st.push(now);
    visited[now] = true;

    if(st.size()==g_v){
        ans++;
        visited[now] = false;
        st.pop();
        return 0;
    }
    for(int i = 0; i < g_v; i++){
        if(c[now][i]==1 && visited[i]==false){
            dfs(i,ans,c,st);
        }
    }
    visited[now] = false;
    st.pop();
    return 0;
}

int main() {
    cin >> g_v >> g_e;

    vector<vector<int>> graph(g_v, vector<int>(g_v,0));

    for(int i=0;i<g_e;i++){
        int src, dst;
        cin >> src >> dst;
        src--; dst--;
        graph[src][dst] = 1;
        graph[dst][src] = 1;
    }
    int ans = 0;
    stack<int> st;

    dfs(0,ans,graph,st);
    cout << ans << endl;

    return 0;
}
