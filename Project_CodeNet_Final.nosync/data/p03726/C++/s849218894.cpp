#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=(x);i<(y);++i)
#define debug(x) #x << "=" << (x)

#ifdef DEBUG
#define _GLIBCXX_DEBUG
#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(x)
#endif

const int inf=1e9;
const int64_t inf64=1e18;
const double eps=1e-9;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){
    os << "[";
    for (const auto &v : vec) {
    	os << v << ",";
    }
    os << "]";
    return os;
}

using i64=int64_t;

void solve(){
    int N;
    cin >> N;
    vector<set<int>> graph(N);
    vector<int> deg(N);
    rep(i,0,N-1){
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    queue<int> que;
    rep(i,0,N) if(graph[i].size()==1) que.push(i);
    vector<bool> done(N);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        if(done[u]) continue;
        done[u]=true;
        if(graph[u].empty()){
            cout << "First" << endl;
            return;
        }
        int v=*graph[u].begin();
        done[v]=true;
        graph[u].clear();
        for(int w:graph[v]){
            graph[w].erase(v);
            if(graph[w].size()==1) que.push(w);
        }
        graph[v].clear();
    }
    cout << "Second" << endl;
}

int main(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(10);
    solve();
    return 0;
}
