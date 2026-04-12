#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    int edge[n][n];
    for(int i=0; i<n; i++){
        fill(edge[i],edge[i]+n,0);
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    queue<pair<int, int* >> que;
    int *vec = new int[n];
    fill(vec,vec+n,0);
    vec[0] = 1;
    que.push(make_pair(0,vec));
    int ans = 0;
    while(!que.empty()){
        pair<int,int*> s = que.front();
        que.pop();
        int v = s.first;
        int* used = s.second;
        int check=1;
        for(int i=0; i<n; i++){
            check*=used[i];
        }
        if(check==1){
            ans++;
            continue;
        }
        for(int i=0; i<n; i++){
            if(i==v) continue;
            if(used[i]==1) continue;
            if(edge[v][i]==0) continue;
            int *vv = new int[n];
            copy(used,used+n,vv);
            vv[i]=1;
            que.push(make_pair(i,vv));
        }
        delete used;
    }
    cout << ans << endl;
    return 0;
}
