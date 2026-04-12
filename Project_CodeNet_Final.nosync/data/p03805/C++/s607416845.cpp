#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> graph[10];
    for(int i=0;i<m;++i){
        int a, b;
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector<int> v;
    for(int i=1;i<=n;++i)v.push_back(i);
    int ans = 0;
    do{
        if(v[0] != 1)continue;
        int cnt = 0;
        for(int i=0;i<n-1;++i){
            if(graph[v[i]].count(v[i+1]))cnt++;
        }
        if(cnt == n - 1)ans++;
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << endl;

    return 0;
}
