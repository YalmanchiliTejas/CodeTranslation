#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
//long long mo = 1e9 + 7;


int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> E(N,(vector<int>()));
    int a,b;
    rep(i,M){
        cin >> a >> b;
        a--;b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    int cnt=0;
    stack<pair<int,int>> st;
    st.push(make_pair(0,0));
    while(!st.empty()){
        int v = st.top().first;
        int s = st.top().second;
        st.pop();
        if(((s >> v) & 1)) continue;
        s += (1 << v);
        if(s == (1 << N) - 1){
            cnt++;
            continue;
        }
        for(auto& next:E[v]){
            st.push(make_pair(next,s));
        }
    }
    cout << cnt << endl;
}
