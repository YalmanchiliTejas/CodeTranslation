#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int V, E;
    cin >> V >> E;
    vector<char> v;
    for(int i=0;i<V;++i){
        char a;
        cin >> a;
        v.push_back(a);
    }
    vector<vector<int>> graph(V, vector<int>());
    for(int i=0;i<E;++i){
        int s, t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }
    for(int i=0;i<V;++i){
        if(v[i] != '?')continue;
        set<char> st;
        for(auto to: graph[i]){
            if(v[to] == '?')continue;
            st.insert(v[to]);
        }
        char c = 'a';
        while(st.count(c))c++;
        v[i] = c;
    }
    for(auto e: v)cout << e;
    cout << endl;

    return 0;
}
